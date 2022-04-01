#ifndef TRENDINGCRYPTOBUTTONCLICKEDEVENT_HPP
#define TRENDINGCRYPTOBUTTONCLICKEDEVENT_HPP

#include<QEvent>

class TrendingCryptoButtonClickedEvent : public QEvent {

public:
    TrendingCryptoButtonClickedEvent() : QEvent(TrendingCryptoButtonClickedEvent::type()) {}
    ~TrendingCryptoButtonClickedEvent() {}

    static const QEvent::Type& type() {
        static QEvent::Type customeventtype = QEvent::None; // Extra
        if(customeventtype == QEvent::None) {
            int generatedtype = QEvent::registerEventType();
            customeventtype = static_cast<QEvent::Type>(generatedtype);
        }
        return customeventtype;
    }
};

#endif // TRENDINGCRYPTOBUTTONCLICKED_HPP
