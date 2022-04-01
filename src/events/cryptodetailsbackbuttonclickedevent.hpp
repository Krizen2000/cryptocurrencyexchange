#ifndef CRYPTODETAILSBACKBUTTONCLICKEDEVENT_HPP
#define CRYPTODETAILSBACKBUTTONCLICKEDEVENT_HPP

#include<QEvent>

class CryptoDetailsBackButtonClickedEvent : public QEvent {

public:
    CryptoDetailsBackButtonClickedEvent() : QEvent(CryptoDetailsBackButtonClickedEvent::type()) {}
    ~CryptoDetailsBackButtonClickedEvent() {}

    static const QEvent::Type& type() {
        static QEvent::Type customeventtype = QEvent::None;
        if(customeventtype == QEvent::None) {
            int generatedtype = QEvent::registerEventType();
            customeventtype = static_cast<QEvent::Type>(generatedtype);
        }
        return customeventtype;
    }
};

#endif // CRYPTODETAILSBACKBUTTONCLICKEDEVENT_HPP
