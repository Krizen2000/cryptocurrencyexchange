#include "cryptocurrencyhandler.h"

//CryptoCurrencyHandler::CryptoCurrencyHandler()
//{

//}

std::vector<std::string> CryptoCurrencyHandler::gettrendingCryptoCurrencyNames() const {
    std::vector<std::string> trendingnames;

    for(auto& element : trendinglist)
        trendingnames.push_back(element.name);

    return trendingnames;
}

const std::vector<std::string> CryptoCurrencyHandler::getCryptoListNames() const {
    std::vector<std::string> requestedcryptolistnames;

    for(auto& item : cryptolist)
        requestedcryptolistnames.push_back(item.name);

    return requestedcryptolistnames;
}

const std::vector<std::string> CryptoCurrencyHandler::getCryptoListSymbols() const{
    std::vector<std::string> requestedcryptolistsymbols;

    for(auto& item : cryptolist)
        requestedcryptolistsymbols.push_back(item.symbol);

    return requestedcryptolistsymbols;
}

std::string CryptoCurrencyHandler::getSymbol(const std::string& name) const
{
    for(auto& item : cryptolist) {
        if(item == name)
            return item.symbol;
    }
    using namespace std::string_literals;
    return ""s;
}


const unsigned long long CryptoCurrencyHandler::getMaxSupplyOf(const std::string& id) const {
    for(auto& requestedcrypto : cryptolist) {
       if(requestedcrypto.name == id || requestedcrypto.symbol == id)
           return requestedcrypto.maxsupply;
    }
    return 0L;
}

const double CryptoCurrencyHandler::getPriceOf(const std::string& id) const {
    for(auto& requestedcrypto : cryptolist) {
       if(requestedcrypto.name == id || requestedcrypto.symbol == id)
           return requestedcrypto.getPrice();
    }
    return 0.0;
}

const double CryptoCurrencyHandler::getMarketCapOf(const std::string& id) const {
    for(auto& requestedcrypto : cryptolist) {
       if(requestedcrypto.name == id || requestedcrypto.symbol == id)
           return requestedcrypto.getMarketCap();
    }
    return 0.0;
}

const void CryptoCurrencyHandler::addTrendingCryptoCurrency(const std::string& id)
{
    if(auto cryptocurrency = getCryptoCurrencyObject(id); cryptocurrency == id)
        trendinglist.push_back(cryptocurrency);
}

const void CryptoCurrencyHandler::removeTrendingCryptoCurrency(const std::string& id)
{
    if(auto cryptocurrency = getCryptoCurrencyObject(id); cryptocurrency == id)
    {
        for(auto ptr = trendinglist.begin(); ptr < trendinglist.end(); ptr++)
        {
            if(*ptr == id)  // This might not work
                trendinglist.erase(ptr);
        }
    }
}


// Update Details related to specific CryptoCurrency


const void CryptoCurrencyHandler::updateCryptoCurrency(const std::string& id,const double& price,const double& marketcap) {
    for(auto& requestedcrypto : cryptolist) {
       if(requestedcrypto.name == id || requestedcrypto.symbol == id) {
           requestedcrypto.setPrice(price);
           requestedcrypto.setMarketCap(marketcap);
       }
    }
}

// Create a new CryptoCurrency Object
//const std::string& symbol, const std::string& name, const std::string& maxsupply, const std::string& price, const std::string& marketcap
const void CryptoCurrencyHandler::createCryptoCurrency(const std::map<std::string,std::string>& data) {
    // ! THIS CAN LEAD TO ERRORS
    using namespace std::string_literals;
    char* tmp;
    unsigned long long t_maxsupply = 0L;
    double t_price = 0.0F;
    double t_marketcap = 0.0F;

    if(const auto& ptr = data.find("maxsupply"s); ptr != data.end())
        t_maxsupply = strtoull(data.at("maxsupply"s).c_str(),&tmp,10);
    if(const auto& ptr = data.find("price"s); ptr != data.end())
        t_price = strtod(data.at("price"s).c_str(),&tmp);
    if(const auto& ptr = data.find("marketcap"s); ptr != data.end())
        t_marketcap = strtod(data.at("marketcap"s).c_str(),&tmp);

    CryptoCurrency newcrypto(data.at("symbol"s),data.at("name"s),t_maxsupply,t_price,t_marketcap);

    cryptolist.push_back(newcrypto);
}

const void CryptoCurrencyHandler::deleteCryptoCurrency(const std::string& id) {
    for(auto i=cryptolist.begin(); i!=cryptolist.end(); i++) {
        if(i->operator==(id))
            cryptolist.erase(i);
    }
}

const CryptoCurrency CryptoCurrencyHandler::getCryptoCurrencyObject(std::string id)
{
    for(auto& element : cryptolist)
        if(element == id)
            return element;
    return CryptoCurrency("","");
    // No error messages for no elements
}

