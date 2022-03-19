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
    if(currentview)
        currentview->hide();
    currentview = viewclasses[windownum];
    currentview->show();
}

const std::string View::getTokenKeyFromView() const
{
    TokenWindow* tmp = static_cast<TokenWindow*>(viewclasses[Window::TOKENWINDOW]);
    return tmp->getTokenKey().toStdString();
}

const void View::setTrendingCurrencies(std::vector<std::string> &trendingcrypto)
{
    std::vector<QString> newtrendingcrypto;

    for(auto& crypto : trendingcrypto)
        newtrendingcrypto.push_back(QString(crypto.c_str()));

    MainWindow* tmp = static_cast<MainWindow*>(viewclasses[Window::MAINWINDOW]);
    tmp->setTrendingCurrency(newtrendingcrypto);
}

const std::string View::getSearchText() const
{
    MainWindow* tmp = static_cast<MainWindow*>(viewclasses[Window::MAINWINDOW]);
    return tmp->getSearchText().toStdString();
}

const void View::setPrice(const std::string &price)
{
    CryptoDetailsWindow* tmp = static_cast<CryptoDetailsWindow*>(viewclasses[Window::CRYPTODETAILSWINDOW]);
    tmp->setPrice(QString(price.c_str()));
}

const void View::setMarketCap(const std::string &marketcap)
{
    CryptoDetailsWindow* tmp = static_cast<CryptoDetailsWindow*>(viewclasses[Window::CRYPTODETAILSWINDOW]);
    tmp->setMarketCap(QString(marketcap.c_str()));
}

const void View::setMaxSupply(const std::string &maxsupply)
{
    CryptoDetailsWindow* tmp = static_cast<CryptoDetailsWindow*>(viewclasses[Window::CRYPTODETAILSWINDOW]);
    tmp->setMaxSupply(QString(maxsupply.c_str()));
}

const void View::setCryptoCurrency(const std::string &cryptocurrency)
{
    CryptoDetailsWindow* tmp = static_cast<CryptoDetailsWindow*>(viewclasses[Window::CRYPTODETAILSWINDOW]);
    tmp->setCryptoCurrency(QString(cryptocurrency.c_str()));
}

View::View(QObject* controller)
{
    this->controller = controller;
    currentview = 0; // Setting to 0

    viewclasses[Window::TOKENWINDOW] = new TokenWindow(controller);   // Changed for Debugging this for event and controller for event filter
    viewclasses[Window::MAINWINDOW] = new MainWindow(controller);
    viewclasses[Window::CRYPTODETAILSWINDOW] = new CryptoDetailsWindow(controller);

    static_cast<QDialog*>(viewclasses[Window::TOKENWINDOW])->open();
    static_cast<QDialog*>(viewclasses[Window::CRYPTODETAILSWINDOW])->open();

    viewclasses[Window::TOKENWINDOW]->hide();
    viewclasses[Window::CRYPTODETAILSWINDOW]->hide();

    changeView(Window::TOKENWINDOW); // NOt good
}

