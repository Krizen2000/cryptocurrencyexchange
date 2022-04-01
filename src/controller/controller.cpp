#include "controller.h"

Controller::Controller(QApplication *application)
{
    this->application = application;

    view = View::getInstance(this);
    model = Model::getInstance(this);
    connection = Connection::getInstance(application); // Needs to be removed
}

Controller *Controller::getInstance(QApplication *application)
{
    static Controller *instance = 0;

    if(!instance)
        new Controller(application);

    return instance;
}

bool Controller::event(QEvent *event)
{
    QEvent *Event = event;
    qDebug() << "Controller Event Override Working !" << (int)Event->type();

    if(Event->type() == ApplicationStartEvent::type()) {
        qDebug() << "Catched ApplicationStartEvent!!!";
        captureApplicationStartEvent(static_cast<ApplicationStartEvent*>(event));
        return true;
    }
    else if(Event->type() == TokenKeyAcquiredEvent::type()) {
        qDebug() << "CAtched TokenKeyAcquiredEvent!!!";
        captureTokenKeyAcquiredEvent(static_cast<TokenKeyAcquiredEvent*>(event));
        return true;
    }
    else if(Event->type() == TrendingCryptoButtonClickedEvent::type()) {
        qDebug() << "Catched TrendingCryptoButtonClickedEvent!!!";
        captureTrendingCryptoButtonClickedEvent(static_cast<TrendingCryptoButtonClickedEvent*>(event));
        return true;
    }
    else if(event->type() == CryptoDetailsBackButtonClickedEvent::type()) {
        qDebug() << "Catched CryptoDetailsBackButtonClickedEvent!!!";
        captureCryptoDetailsBackButtonClickedEvent(static_cast<CryptoDetailsBackButtonClickedEvent*>(event));
        return true;
    }
        return false;
}

void Controller::captureApplicationStartEvent(ApplicationStartEvent *event)
{
    view->changeView(View::TOKENWINDOW);
}

void Controller::captureTokenKeyAcquiredEvent(TokenKeyAcquiredEvent *event)
{
    model->setToken(view->getTokenKeyFromView());
    auto tmp = model->gettrendingCryptoCurrencyNames();
    view->setTrendingCurrencies(tmp);
    view->changeView(View::MAINWINDOW);
}

void Controller::captureTrendingCryptoButtonClickedEvent(TrendingCryptoButtonClickedEvent *event)
{
    using namespace std::string_literals;

    std::string cryptoname = view->getClickedButton();
    std::map<std::string,std::string> data;

    try
    {
        data = connection->retrieveData(model->getSymbol(cryptoname),model->getToken());
    }
    catch(std::exception const& er)         // Exceptions related to Network are catched
    {
        qDebug() << "Error: " << er.what();
        view->displayErrorMessageBox(er.what());
        return;
    }

    view->setPrice(data.at("price"s));
    view->setMarketCap(data.at("marketcap"s));

    if(auto maxsupply = data.at("maxsupply"s); maxsupply == ""s)
        view->setMaxSupply("No Upper Bound"s);
    else
        view->setMaxSupply(data.at("maxsupply"s));

    view->setSymbol(model->getSymbol(cryptoname));
    view->setCryptoCurrency(cryptoname);
    view->setCryptoCurrencyImage(model->getImage(cryptoname));

    view->changeView(View::Window::CRYPTODETAILSWINDOW);
}

void Controller::captureCryptoDetailsBackButtonClickedEvent(CryptoDetailsBackButtonClickedEvent *event)
{
    view->changeView(View::Window::MAINWINDOW);
}

