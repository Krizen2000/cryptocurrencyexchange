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
        addTrendingCryptoCurrency(name);
    }
    auto dataimage = dataImageFunction();
    for(auto [ name, image ] : dataimage )
    {
        QPixmap* img = new QPixmap(image.c_str());
        iconpack.insert({name,img});
    }
}

Model* Model::getInstance(QObject* controller)
{
    static Model* instance = 0;
    if(!instance)
        instance = new Model(controller);
    return instance;
}

std::vector<std::string> Model::gettrendingCryptoCurrencyNames() const
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

const void Model::addTrendingCryptoCurrency(std::string id)
{
    cryptohandler->addTrendingCryptoCurrency(id);
}

const void Model::removeTrendingCryptoCurrency(std::string id)
{
    cryptohandler->removeTrendingCryptoCurrency(id);
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

const void Model::addImage(std::string id,QPixmap *image)
{
    iconpack.insert({id,image});
}

QPixmap *Model::getImage(std::string id)
{
    return iconpack.at(id);
}

std::string Model::getSymbol(const std::string &name)
{
    return cryptohandler->getSymbol(name);
}



std::map<std::string,std::string> dataFunction()
{
    using namespace std::string_literals;
    std::map<std::string,std::string> item{ {"bitcoin"s,"BTC"s,}, {"ethereum"s,"ETH"s}, {"monero"s,"XMR"s}, {"litecoin"s,"LTC"s} };
    return item;
}


std::map<std::string, std::string> dataImageFunction()
{
    using namespace std::string_literals;
    std::map<std::string,std::string> item{ {"bitcoin"s,":/rc/img/bitcoinicon.png"s,}, {"ethereum"s,":/rc/img/ethereumicon.png"s}, {"monero"s,":/rc/img/moneroicon.png"s}, {"litecoin"s,":/rc/img/litecoinicon.png"s} };
    return item;
}
