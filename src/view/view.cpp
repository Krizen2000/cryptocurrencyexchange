#include "view.h"

View *View::getInstance(QObject* controller)
{
    static View* instance = 0;
    if(!instance)
        instance = new View(controller);
    return instance;
}

const void View::changeView(Window windownum)
{
    mainwindow->changeView(windownum);
}

const std::string View::getTokenKeyFromView() const
{
    return mainwindow->getTokenKey().toStdString();
}

const void View::setTrendingCurrencies(std::vector<std::string> &trendingcrypto)
{
    std::vector<QString> newtrendingcrypto;

    for(auto& crypto : trendingcrypto)
        newtrendingcrypto.push_back(QString(crypto.c_str()));

    mainwindow->setTrendingCurrencies(newtrendingcrypto);
}

const std::string View::getSearchText() const
{
    return mainwindow->getSearchText().toStdString();
}

const void View::setPrice(std::string price)
{
    mainwindow->setPrice(QString::fromStdString(price));
}

const void View::setMarketCap(std::string marketcap)
{
    mainwindow->setMarketCap(QString::fromStdString(marketcap));
}

const void View::setMaxSupply(std::string maxsupply)
{
    mainwindow->setMaxSupply(QString::fromStdString(maxsupply));
}

const void View::setCryptoCurrency(std::string cryptocurrency)
{
    mainwindow->setCryptoCurrency(QString::fromStdString(cryptocurrency));
}

const void View::setDescription(std::string description)
{
    mainwindow->setDescription(QString::fromStdString(description));
}

const void View::setCryptoCurrencyImage(QPixmap *image)
{
    mainwindow->setCryptoCurrencyImage(image);
}

View::View(QObject* controller)
{
    this->controller = controller;

    mainwindow = new MainWindow(controller);
    mainwindow->show();

    changeView(Window::TOKENWINDOW);
}

