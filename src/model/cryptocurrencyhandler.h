#ifndef CRYPTOCURRENCYHANDLER_H
#define CRYPTOCURRENCYHANDLER_H

#include"cryptocurrency.hpp"

#include<string>
#include<functional>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdlib>

class CryptoCurrencyHandler {

public:

    std::vector<std::string> gettrendingCryptoCurrencyNames() const;
    const std::vector<std::string> getCryptoListNames() const;
    const std::vector<std::string> getCryptoListSymbols() const;
    std::string getSymbol(const std::string& name) const;

    // !!! No handler for Error raised by not getting reference for object requestedcrypto

    const unsigned long long getMaxSupplyOf(const std::string& id) const;
    const double getPriceOf(const std::string& id) const;
    const double getMarketCapOf(const std::string& id) const;

    const void addTrendingCryptoCurrency(const std::string& id);
    const void removeTrendingCryptoCurrency(const std::string& id);

    const void updateCryptoCurrency(const std::string& id,const double& price,const double& marketcap);
    const void createCryptoCurrency(const std::map<std::string,std::string>& data);
    const void deleteCryptoCurrency(const std::string& id);

private:
    std::vector<CryptoCurrency> cryptolist;
    std::vector<CryptoCurrency> trendinglist;

    const CryptoCurrency getCryptoCurrencyObject(std::string id);
};
#endif // CRYPTOCURRENCYHANDLER_H
