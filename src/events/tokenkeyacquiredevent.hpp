#ifndef TOKENKEYACQUIREDEVENT_HPP
#define TOKENKEYACQUIREDEVENT_HPP

#include<QEvent>

class TokenKeyAcquiredEvent : public QEvent {

public:
    TokenKeyAcquiredEvent() : QEvent(TokenKeyAcquiredEvent::type()) {}
    ~TokenKeyAcquiredEvent() {}

    static const QEvent::Type& type() {
        static QEvent::Type customeventtype = QEvent::None;
        if(customeventtype == QEvent::None) {
            int generatedtype = QEvent::registerEventType();
            customeventtype = static_cast<QEvent::Type>(generatedtype);
        }
        return customeventtype;
    }
};

#endif // TOKENKEYACQUIREDEVENT_HPP
