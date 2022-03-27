#ifndef CRYPTOCURRENCY_H
#define CRYPTOCURRENCY_H

#include<string>
#include<boost/algorithm/string.hpp>

struct CryptoCurrency {
    CryptoCurrency(const std::string symbol,const std::string name, unsigned long long maxsupply = 0L, double price = 0.00F, double marketcap = 0.00F) : symbol(symbol) ,name(name), maxsupply(maxsupply), price(price), marketcap(marketcap) {}
//    CryptoCurrency() : symbol("null"), name("null"), maxsupply(0L), price(0.0), marketcap(0.0) {}

    // Copy Constructor
//    CryptoCurrency(CryptoCurrency crypto) : symbol(crypto.symbol), name(crypto.name), maxsupply(crypto.maxsupply), price(crypto.getPrice()), marketcap(crypto.getMarketCap()) {}


    std::string symbol;
    std::string name;
    unsigned long long maxsupply;

private:
    double price;
    double marketcap;
public:

    const double getPrice() const {
        return price;
    }
    const double getMarketCap() const {
        return marketcap;
    }

    void setPrice(const double price) {
        this->price = price;
    }
    void setMarketCap(const double marketcap) {
        this->marketcap = marketcap;
    }

    const bool operator== (const CryptoCurrency& crypto) const {
        return symbol == crypto.symbol && name == crypto.name;
    }
    const bool operator== (std::string id) const {  // Something is not working here
//        return symbol.compare(boost::to_upper_copy(id).c_str()) || name.compare(boost::to_lower_copy(id).c_str());
        return symbol == boost::to_upper_copy(id) || name == boost::to_lower_copy(id);
    }
};

#endif // CRYPTOCURRENCY_H
