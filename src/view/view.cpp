#include "view.h"

View *View::getInstance(QObject *controller)
{
    static View *instance = 0;
    if(!instance)
        instance = new View(controller);
    return instance;
}

const void View::changeView(Window windownum) const
{
    mainwindow->changeView(windownum);
}

const std::string View::getTokenKeyFromView() const
{
    return mainwindow->getTokenKey().toStdString();
}

const void View::setTrendingCurrencies(const std::vector<std::string> &trendingcrypto) const
{
    std::vector<QString> newtrendingcrypto;

    for(const auto& crypto : trendingcrypto)
        newtrendingcrypto.push_back(QString(crypto.c_str()));

    mainwindow->setTrendingCurrencies(newtrendingcrypto);
}

const std::string View::getSearchText() const
{
    return mainwindow->getSearchText().toStdString();
}

const std::string View::getClickedButton() const
{
    return mainwindow->getClickedButtonName().toStdString();
}

const void View::setPrice(const std::string &price) const
{
    mainwindow->setPrice(QString::fromStdString(price));
}

const void View::setMarketCap(const std::string &marketcap) const
{
    mainwindow->setMarketCap(QString::fromStdString(marketcap));
}

const void View::setMaxSupply(const std::string &maxsupply) const
{
    mainwindow->setMaxSupply(QString::fromStdString(maxsupply));
}

const void View::setSymbol(const std::string &symbol) const
{
    mainwindow->setSymbol(QString::fromStdString(symbol));
}

const void View::setCryptoCurrency(const std::string &cryptocurrency) const
{
    mainwindow->setCryptoCurrency(QString::fromStdString(cryptocurrency));
}

const void View::setDescription(const std::string &description) const
{
    mainwindow->setDescription(QString::fromStdString(description));
}

const void View::setCryptoCurrencyImage(const QPixmap *image) const
{
    mainwindow->setCryptoCurrencyImage(image);
}

const void View::displayErrorMessageBox(const std::string& errmsg) const
{
    static QMessageBox *errormsgbox = 0;

    if(!errormsgbox)
        delete errormsgbox;

    errormsgbox = new QMessageBox();
    errormsgbox->setText(errmsg.c_str());
    errormsgbox->exec();
}

View::View(QObject *controller)
{
    this->controller = controller;

    mainwindow = new MainWindow(controller);
    mainwindow->show();

    changeView(Window::TOKENWINDOW); // Should be changed and use Event instead
}

