#include "connection.h"

Connection::Connection(QApplication* application)
{
    Connection::application = application;
}
        // FAcked UP CodE
Connection* Connection::getInstance(QApplication* application) { // ? Can use reference pointer
    static Connection* instance = 0;
    if(!instance)
        instance = new Connection(application);
    return instance;
}

std::string Connection::httpsRequest(std::string host,std::string port,const std::string& query, const std::string& key) {

    // Declaring Namespaces for Convinience
    namespace net = boost::asio;
    namespace beast = boost::beast;
    namespace http = boost::beast::http;
    namespace ssl = net::ssl;

//    try {         // Removed and handling of network is forwarded to Class Controller
        net::io_context context;
        ssl::context ctx(ssl::context::tlsv12_client);

        ctx.set_verify_mode(ssl::verify_none);

        net::ip::tcp::resolver resolver(context);
        beast::ssl_stream<beast::tcp_stream> stream(context, ctx);

        if(! SSL_set_tlsext_host_name(stream.native_handle(),host.c_str())) {
            beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
            throw beast::system_error{ec};
        }

        auto const results = resolver.resolve(host,port);
        beast::get_lowest_layer(stream).connect(results);

        stream.handshake(ssl::stream_base::client);

        // TLS Handshake Completed
        // Initiating HTTPS Request

        http::request<http::string_body> req(http::verb::get,query,11); // 11
        req.set(http::field::host,host);
        req.set("X-CMC_PRO_API_KEY",key);
        req.set("Accept","application/json");
        req.prepare_payload();

        http::write(stream,req);
        beast::flat_buffer buffer;


        http::response<http::dynamic_body> res;
        http::read(stream,buffer,res);

//        std::cout << res << '/n';

        // Shutting down the socket
        beast::error_code ec;
        stream.shutdown(ec);

        return beast::buffers_to_string(res.body().data());
//    }
//    catch(std::exception const& er) {
//        std::cerr << "Error: " << er.what() << std::endl; // Change this for support for Bad Connection
//        return std::string("ERROR");
//    }
//    return std::string("???");
}

std::map<std::string,std::string> Connection::parseJson(std::string symbol,const std::string& data) {

    using namespace std::string_literals;

    using boost::property_tree::ptree;
    using boost::property_tree::read_json;

    std::map<std::string,std::string> jsonattributes;

    ptree jsonfile;
    std::stringstream ss(data);

    read_json(ss,jsonfile);

    std::string str;

    boost::to_upper(symbol);

    str = "data."s + symbol + ".quote.USD.price"s;
    jsonattributes.insert({"price"s, jsonfile.get<std::string>(str)});
    str = "data."s + symbol + ".quote.USD.market_cap"s;
    jsonattributes.insert({"marketcap"s, jsonfile.get<std::string>(str)});
    str = "data."s + symbol + ".max_supply"s;
    jsonattributes.insert({"maxsupply"s, static_cast<std::string>( jsonfile.get<std::string>(str) )});

    return jsonattributes;
}

std::map<std::string,std::string> Connection::retrieveData(std::string symbol, const std::string& key) {
    std::string host = "pro-api.coinmarketcap.com", port = "443";
    std::string query = "/v1/cryptocurrency/quotes/latest?symbol=";

    boost::to_lower(symbol);
    query += symbol;

    std::map<std::string,std::string> data;

    std::string response = httpsRequest(host,port,query,key);
    data = parseJson(symbol,response);
    return data;
}

std::vector<std::map<std::string,std::string>> Connection::retrieveAllData(std::vector<std::string> symbol, const std::string& key) {
    std::vector<std::map<std::string,std::string>> data;

    for(auto& item : symbol)
        data.push_back(retrieveData(item,key));
    return data;
}

//void Connection::ApplicationStartedEvent(ApplicationStartEvent* event) {

//}
