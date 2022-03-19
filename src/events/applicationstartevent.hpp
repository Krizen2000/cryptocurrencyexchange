#ifndef APPLICATIONSTARTEVENT_HPP
#define APPLICATIONSTARTEVENT_HPP

#include<QEvent>

class ApplicationStartEvent :public QEvent {
public:
    ApplicationStartEvent() : QEvent(ApplicationStartEvent::type()) {}

    virtual ~ApplicationStartEvent() {}

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

#endif // APPLICATIONSTARTEVENT_HPP
