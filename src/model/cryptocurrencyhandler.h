#ifndef CRYPTOCURRENCYHANDLER_H
#define CRYPTOCURRENCYHANDLER_H

#include"cryptocurrency.hpp"

#include<string>
#include<functional>
#include<algorithm>
//#include<iterator>
#include<map>
#include<vector>
#include<cstdlib>

class CryptoCurrencyHandler {

private:
    std::vector<CryptoCurrency> cryptolist;
    std::vector<CryptoCurrency> trendinglist;

public:

    // CONTROLLER METHODS PUBLICILY AVALIABLE

    const std::vector<std::string> gettrendingCryptoCurrencyNames() const;
    const std::vector<std::string> getCryptoListNames() const;
    const std::vector<std::string> getCryptoListSymbols() const;
    std::string getSymbol(std::string name) const;

    // Get Details related to specific CryptoCurrency
    // !!! No handler for Error raised by not getting reference for object requestedcrypto

    const unsigned long long getMaxSupplyOf(const std::string& id) const;
    const double getPriceOf(const std::string& id) const;
    const double getMarketCapOf(const std::string& id) const;

    const void updateCryptoCurrency(const std::string& id,const double& price,const double& marketcap);
//    const void createCryptoCurrency(const std::string& symbol, const std::string& name, const std::string& maxsupply, const std::string& price, const std::string& marketcap);
    const void createCryptoCurrency(std::map<std::string,std::string>& data);
    const void deleteCryptoCurrency(const std::string& id);
};
#endif // CRYPTOCURRENCYHANDLER_H
