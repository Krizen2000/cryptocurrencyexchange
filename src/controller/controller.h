#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<QObject>
#include<QApplication>
#include<QEvent>
#include<string>
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

    // These are all Event Observers
protected:
    bool event(QEvent* event) override;
//    void customEvent(QEvent* event) override;
    bool eventFilter(QObject* dest, QEvent* event);
    bool eventFilter2(QObject* dest, ApplicationStartEvent* event);
    bool eventFilter3(QObject* dest, TokenKeyAcquiredEvent* event);
    bool eventFilter4(QObject* dest, TrendingCryptoButtonClickedEvent* event);
    bool eventFilter5(QObject* dest, CryptoDetailsBackButtonClickedEvent* event);

private:
    Model* model;
    View* view;
    QApplication* application;
    Connection* connection;
};


#endif // CONTROLLER_H
