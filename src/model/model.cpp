#include "src/model/model.h"

Model::Model(QObject* controller)
{
    this->controller = controller;
    cryptohandler = new CryptoCurrencyHandler();
    userdata = new UserData();

    // Need to add some sort of persistent storage support

    auto data = dataFunction();
    using namespace std::string_literals;
    for(auto [ name, symbol ] : data)
    {
        std::map<std::string,std::string> tmp{{"name"s,name},{"symbol"s,symbol}};
        createCryptoCurrency(tmp);
    }
}

Model* Model::getInstance(QObject* controller)
{
    static Model* instance = 0;
    if(!instance)
        instance = new Model(controller);
    return instance;
}

const std::vector<std::string> Model::gettrendingCryptoCurrencyNames() const
{
    return cryptohandler->gettrendingCryptoCurrencyNames();
}

const std::vector<std::string> Model::getCryptoListNames() const
{
    return cryptohandler->getCryptoListNames();
}

const std::vector<std::string> Model::getCryptoListSymbols() const
{
    return cryptohandler->getCryptoListSymbols();
}

const unsigned long long Model::getMaxSupplyOf(const std::string &id) const
{
    return cryptohandler->getMaxSupplyOf(id);
}

const double Model::getPriceOf(const std::string &id) const
{
    return cryptohandler->getPriceOf(id);
}

const double Model::getMarketCapOf(const std::string &id) const
{
    return cryptohandler->getMarketCapOf(id);
}

const void Model::updateCryptoCurrency(const std::string &id, const double &price, const double &marketcap)
{
    cryptohandler->updateCryptoCurrency(id,price,marketcap);
}

const void Model::createCryptoCurrency(std::map<std::string, std::string> &data)
{
    cryptohandler->createCryptoCurrency(data);
}

const void Model::deleteCryptoCurrency(const std::string &id)
{
    cryptohandler->deleteCryptoCurrency(id);
}

const std::string Model::getToken() const
{
    return userdata->getToken();
}

const void Model::setToken(const std::string& token)
{
    userdata->setToken(token);
}

const bool Model::tokenExist() const
{
    return userdata->tokenExist();
}

std::string Model::getSymbol(const std::string &name)
{
    return cryptohandler->getSymbol(name);
}



std::map<std::string,std::string> dataFunction()
{
    using namespace std::string_literals;
    std::map<std::string,std::string> item{ {"bitcoin"s,"BTC"s}, {"ethereum"s,"ETH"s}, {"monero"s,"XMR"s}, {"litecoin"s,"LTC"s} };
    return item;
}
