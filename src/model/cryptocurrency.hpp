#ifndef CRYPTOCURRENCY_H
#define CRYPTOCURRENCY_H

#include<string>
#include<boost/algorithm/string.hpp>

struct CryptoCurrency {

    CryptoCurrency(const std::string& symbol,const std::string& name,const unsigned long long maxsupply = 0L,const double price = 0.00F,const double marketcap = 0.00F) : symbol(symbol) ,name(name), maxsupply(maxsupply), price(price), marketcap(marketcap) {}

    std::string symbol;
    std::string name;
    unsigned long long maxsupply;

public:

    const double getPrice() const {return price;}
    const double getMarketCap() const {return marketcap;}

    void setPrice(const double price) {this->price = price;}
    void setMarketCap(const double marketcap) {this->marketcap = marketcap;}

    const bool operator== (const CryptoCurrency& crypto) const {
        return symbol == crypto.symbol && name == crypto.name;
    }
    const bool operator== (const std::string& id) const {
        return symbol == boost::to_upper_copy(id) || name == boost::to_lower_copy(id);
    }

private:

    double price;
    double marketcap;

};

#endif // CRYPTOCURRENCY_H
