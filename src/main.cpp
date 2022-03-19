//#include "src/view/mainwindow/mainwindow.h"
//#include "src/view/dialog.h"

#include <QApplication>
#include"src/controller/controller.h"
#include"src/events/applicationstartevent.hpp"
#include"src/events/tokenkeyacquiredevent.hpp"

int main(int argc, char *argv[])
{
    QApplication appinstance(argc, argv);

    Controller* controller = Controller::getInstance(&appinstance);
//    QApplication::postEvent(&appinstance,new TokenKeyAcquiredEvent());

    return appinstance.exec();
}
