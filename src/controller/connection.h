#ifndef CONNECTION_H
#define CONNECTION_H

#include<iostream>
#include<string>
#include<boost/algorithm/string.hpp>
#include<map>
#include<vector>
#include<QApplication>

#include"src/events/applicationstartevent.hpp"

#include<boost/asio.hpp>
#include<boost/beast/core.hpp>
#include<boost/beast/http.hpp>

#include<boost/beast/ssl.hpp>
#include<boost/beast/version.hpp>
#include<boost/asio/connect.hpp>
#include<boost/asio/ip/tcp.hpp>
#include<boost/asio/ssl/error.hpp>
#include<boost/asio/ssl/stream.hpp>
#include<openssl/opensslconf.h>

#include<sstream>
#include<boost/property_tree/ptree.hpp>
#include<boost/property_tree/json_parser.hpp>


class Connection
{

public:
    static Connection* getInstance(QApplication *application);

    /** Raises Exception */
    std::map<std::string,std::string> retrieveData(const std::string &symbol, const std::string &key);
    std::vector<std::map<std::string,std::string>> retrieveAllData(const std::vector<std::string> &symbol, const std::string &key);

    void ApplicationStartedEvent(ApplicationStartEvent *event);

private:
    QApplication *application;

    Connection(QApplication *application);

    std::string httpsRequest(const std::string &host,const std::string &port,const std::string &query, const std::string &key);
    std::map<std::string,std::string> parseJson(const std::string &symbol, const std::string &data);

};


#endif // CONNECTION_H
