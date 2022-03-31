#include "controller.h"

Controller::Controller(QApplication *application)
{
    this->application = application;

    view = View::getInstance(this);
    model = Model::getInstance(this);
    connection = Connection::getInstance(application); // Needs to be removed

//    view->installEventFilter(this);
//    model->installEventFilter(this);

}

Controller *Controller::getInstance(QApplication *application)
{
    static Controller* instance;
    if(!instance)
        new Controller(application);
    return instance;
}

bool Controller::event(QEvent *event)
{
    QEvent* Event = event;
    qDebug() << "Controller Event Override Working !" << (int)Event->type();
    if(Event->type() == ApplicationStartEvent::type()) {
        qDebug() << "Catched ApplicationStartEvent!!!";
        return eventFilter2(nullptr,(ApplicationStartEvent*)event);
    }
    else if(Event->type() == TokenKeyAcquiredEvent::type()) {
        qDebug() << "CAtched TokenKeyAcquiredEvent!!!";
        return eventFilter3(nullptr,(TokenKeyAcquiredEvent*)event);
    }
    else if(Event->type() == TrendingCryptoButtonClickedEvent::type()) {
        qDebug() << "Catched TrendingCryptoButtonClickedEvent!!!";
        return eventFilter4(nullptr,(TrendingCryptoButtonClickedEvent*)event);
    }
    else if(event->type() == CryptoDetailsBackButtonClickedEvent::type()) {
        qDebug() << "Catched CryptoDetailsBackButtonClickedEvent!!!";
        return eventFilter5(nullptr,(CryptoDetailsBackButtonClickedEvent*)event);
    }
    else
        return false;
}

//void Controller::customEvent(QEvent *event)
//{
//    QEvent* Event = event;
//    qDebug() << "Controller Event Override Working !" << (int)Event->type();
//    if(Event->type() == ApplicationStartEvent::type()) {
//        qDebug() << "Catched ApplicationStartEvent!!!";
//        eventFilter2(nullptr,(ApplicationStartEvent*)event);
//    }
//    else if(Event->type() == TokenKeyAcquiredEvent::type()) {
//        qDebug() << "CAtched TokenKeyAcquiredEvent!!!";
//        eventFilter3(nullptr,(TokenKeyAcquiredEvent*)event);
//    }
//    else if(Event->type() == TrendingCryptoButtonClickedEvent::type()) {
//        qDebug() << "Catched TrendingCryptoButtonClickedEvent!!!";
//        eventFilter4(nullptr,(TrendingCryptoButtonClickedEvent*)event);
//    }
//}

// This is disabled because using QObjects Default Event Listener
bool Controller::eventFilter(QObject *dest, QEvent *event)
{
    qDebug() << "Controller EventFilter Override Working !" << (int)event->type();
    if(event->type() == ApplicationStartEvent::type()) {
        qDebug() << "Catched ApplicationStartEvent!!!";
        return eventFilter2(dest,(ApplicationStartEvent*)event);
    }
    else if(event->type() == TokenKeyAcquiredEvent::type()) {
        qDebug() << "CAtched TokenKeyAcquiredEvent!!!";
        return eventFilter3(dest,(TokenKeyAcquiredEvent*)event);
    }
    else if(event->type() == TrendingCryptoButtonClickedEvent::type()) {
        qDebug() << "Catched TrendingCryptoButtonClickedEvent!!!";
        return eventFilter4(dest,(TrendingCryptoButtonClickedEvent*)event);
    }
    else if(event->type() == CryptoDetailsBackButtonClickedEvent::type()) {
        qDebug() << "Catched CryptoDetailsBackButtonClickedEvent!!!";
        return eventFilter5(dest,(CryptoDetailsBackButtonClickedEvent*)event);
    }
    else
        return QObject::eventFilter(dest,event);
}

bool Controller::eventFilter2(QObject *dest, ApplicationStartEvent *event)
{
    view->changeView(View::TOKENWINDOW);

    return true;
//    return QObject::eventFilter(dest,event);
}

bool Controller::eventFilter3(QObject *dest, TokenKeyAcquiredEvent *event)
{
    model->setToken(view->getTokenKeyFromView());
    auto tmp = model->gettrendingCryptoCurrencyNames();
    view->setTrendingCurrencies(tmp);
    view->changeView(View::MAINWINDOW);

    return true;
//    return QObject::eventFilter(dest,event);
}

bool Controller::eventFilter4(QObject *dest, TrendingCryptoButtonClickedEvent *event)
{
    using namespace std::string_literals;
//    std::string cryptoname = event->getCryptoCurrency();
    std::string cryptoname = view->getClickedButton(); // Gets name from function rather then Event
//    std::map<std::string,std::string> data = connection->retrieveData(model->getSymbol(cryptoname),model->getToken());
    std::map<std::string,std::string> data;
    try {
        data = connection->retrieveData(model->getSymbol(cryptoname),model->getToken());
    } catch(std::exception const& er) {     // Exceptions related to Network are catched
        qDebug() << "Error: " << er.what();
        // Make a error messageBox in View
        view->displayErrorMessageBox(er.what());
        return false;
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

    return true;
    //    return QObject::eventFilter(dest,event);
}

bool Controller::eventFilter5(QObject *dest, CryptoDetailsBackButtonClickedEvent *event)
{
    view->changeView(View::Window::MAINWINDOW);
    return true;
}

