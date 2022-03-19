#ifndef TRENDINGCRYPTOBUTTONCLICKEDEVENT_HPP
#define TRENDINGCRYPTOBUTTONCLICKEDEVENT_HPP

#include<QEvent>
#include<string>

class TrendingCryptoButtonClickedEvent : public QEvent {
public:
    explicit TrendingCryptoButtonClickedEvent(std::string cryptocurrency) : QEvent(TrendingCryptoButtonClickedEvent::type()), cryptocurrency(cryptocurrency) {}

    virtual ~TrendingCryptoButtonClickedEvent() {}

    static const QEvent::Type& type() {
        static QEvent::Type customeventtype = QEvent::None; // Extra
        if(customeventtype == QEvent::None) {
            int generatedtype = QEvent::registerEventType();
            customeventtype = static_cast<QEvent::Type>(generatedtype);
        }
        return customeventtype;
    }
    const std::string getCryptoCurrency() const {
        return cryptocurrency;
    }
private:
//    static QEvent::Type customeventtype;
    const std::string cryptocurrency;
};

#endif // TRENDINGCRYPTOBUTTONCLICKED_HPP
