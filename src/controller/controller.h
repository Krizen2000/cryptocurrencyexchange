#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QObject>
#include<QApplication>
#include<QEvent>
#include<string>
#include<exception>
#include<map>

#include"src/model/model.h"
#include"src/view/view.h"
#include"src/controller/connection.h"

// Event Classes
#include"src/events/applicationstartevent.hpp"
#include"src/events/tokenkeyacquiredevent.hpp"
#include"src/events/trendingcryptobuttonclickedevent.hpp"
#include"src/events/cryptodetailsbackbuttonclickedevent.hpp"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QApplication* application);
    static Controller* getInstance(QApplication* application);

protected:
    bool event(QEvent* event) override;

private:
    Model *model;
    View *view;
    QApplication *application;
    Connection *connection;

    // These are all Event Dispatcher
    void captureApplicationStartEvent(ApplicationStartEvent *event);
    void captureTokenKeyAcquiredEvent(TokenKeyAcquiredEvent *event);
    void captureTrendingCryptoButtonClickedEvent(TrendingCryptoButtonClickedEvent *event);
    void captureCryptoDetailsBackButtonClickedEvent(CryptoDetailsBackButtonClickedEvent *event);
};


#endif // CONTROLLER_H
