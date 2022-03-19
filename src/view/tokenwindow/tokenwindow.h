#ifndef TOKENWINDOW_H
#define TOKENWINDOW_H

#include <QDialog>
#include<QWidget>
#include<QObject>
#include<QApplication>
#include<QString>

#include"src/events/tokenkeyacquiredevent.hpp"

namespace Ui {
class TokenWindow;
}

class TokenWindow : public QDialog
{
    Q_OBJECT

public:
    ~TokenWindow();
    explicit TokenWindow(QObject* controller,QWidget *parent = nullptr);

    QString getTokenKey();

private slots:
    void on_nextbutton_clicked();

private:
    Ui::TokenWindow *ui;
    QObject* controller;
};

#endif // TOKENWINDOW_H
