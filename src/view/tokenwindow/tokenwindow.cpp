#include "tokenwindow.h"
#include "ui_tokenwindow.h"
#include <iostream>

TokenWindow::TokenWindow(QObject* controller,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TokenWindow)
{
    ui->setupUi(this);
    this->controller = controller;
}

TokenWindow::~TokenWindow()
{
    delete ui;
}

void TokenWindow::on_nextbutton_clicked()
{
//    QPushButton::eventFilter(0)
//    if(! ui->token->text().isEmpty())
//        return;
//    TokenKeyAcquiredEvent tm;
    QEvent* eventd = new TokenKeyAcquiredEvent();         // Needs more work
    QCoreApplication::sendEvent(controller,eventd);
    qDebug() << "NextButtonCLickedEvent!!!";
    std::cout << "NextButtonCLickedEvent!!!";
}

QString TokenWindow::getTokenKey()
{
    return ui->token->text();
}
