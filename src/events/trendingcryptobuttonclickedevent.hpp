#ifndef TRENDINGCRYPTOBUTTONCLICKEDEVENT_HPP
#define TRENDINGCRYPTOBUTTONCLICKEDEVENT_HPP

#include<QEvent>
#include<string>

class TrendingCryptoButtonClickedEvent : public QEvent {
public:
    explicit TrendingCryptoButtonClickedEvent() : QEvent(TrendingCryptoButtonClickedEvent::type()) {}

    virtual ~TrendingCryptoButtonClickedEvent() {}

    static const QEvent::Type& type() {
        static QEvent::Type customeventtype = QEvent::None; // Extra
        if(customeventtype == QEvent::None) {
            int generatedtype = QEvent::registerEventType();
            customeventtype = static_cast<QEvent::Type>(generatedtype);
        }
        return customeventtype;
    }
private:
//    static QEvent::Type customeventtype;
};

#endif // TRENDINGCRYPTOBUTTONCLICKED_HPP
