#ifndef MODEL_H
#define MODEL_H

#include<QObject>
#include<string>
#include<map>
#include"src/model/cryptocurrencyhandler.h"
#include"src/model/userdata.hpp"

class Model : public QObject
{
    Q_OBJECT
public:
    static Model* getInstance(QObject* controller);

    // Methods of CryptoCurrencyHandler
    const std::vector<std::string> gettrendingCryptoCurrencyNames() const;
    const std::vector<std::string> getCryptoListNames() const;
    const std::vector<std::string> getCryptoListSymbols() const;

    const unsigned long long getMaxSupplyOf(const std::string& id) const;
    const double getPriceOf(const std::string& id) const;
    const double getMarketCapOf(const std::string& id) const;

    const void updateCryptoCurrency(const std::string& id,const double& price,const double& marketcap);
    const void createCryptoCurrency(std::map<std::string,std::string>& data);
    const void deleteCryptoCurrency(const std::string& id);

    // Methods of UserData
    std::string getSymbol(const std::string& name);
    const std::string getToken() const;
    const void setToken(const std::string& token);
    const bool tokenExist() const;

private:
    QObject* controller;

    CryptoCurrencyHandler* cryptohandler;
    UserData* userdata;

    explicit Model(QObject* controller);

};

std::map<std::string,std::string> dataFunction();
//Model* Model::instance = 0;
//QApplication* Model::application = 0;

#endif // MODEL_H
