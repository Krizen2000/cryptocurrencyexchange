#ifndef APPLICATIONSTARTEVENT_HPP
#define APPLICATIONSTARTEVENT_HPP

#include<QEvent>

class ApplicationStartEvent :public QEvent {
public:
    ApplicationStartEvent() : QEvent(ApplicationStartEvent::type()) {}
    ~ApplicationStartEvent() {}

    static const QEvent::Type& type() {
        static QEvent::Type customeventtype = QEvent::None;
        if(customeventtype == QEvent::None) {
            int generatedtype = QEvent::registerEventType();
            customeventtype = static_cast<QEvent::Type>(generatedtype);
        }
        return customeventtype;
    }
};

#endif // APPLICATIONSTARTEVENT_HPP
