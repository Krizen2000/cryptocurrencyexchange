#ifndef TOKENKEYACQUIREDEVENT_HPP
#define TOKENKEYACQUIREDEVENT_HPP

#include<QEvent>

class TokenKeyAcquiredEvent : public QEvent {
public:
    TokenKeyAcquiredEvent() : QEvent(TokenKeyAcquiredEvent::type()) {}

    virtual ~TokenKeyAcquiredEvent() {}

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

#endif // TOKENKEYACQUIREDEVENT_HPP
