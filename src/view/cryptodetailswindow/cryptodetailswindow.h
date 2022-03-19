#ifndef CRYPTODETAILSWINDOW_H
#define CRYPTODETAILSWINDOW_H

#include <QDialog>
#include<QWidget>
#include<QObject>
#include<QString>

#include"src/events/cryptodetailsbackbuttonclickedevent.hpp"

namespace Ui {
class CryptoDetailsWindow;
}

class CryptoDetailsWindow : public QDialog
{
    Q_OBJECT

public:
    CryptoDetailsWindow(QObject* controller,QWidget *parent = nullptr);
    ~CryptoDetailsWindow();

    const void setPrice(const QString& price);
    const void setMarketCap(const QString& marketcap);
    const void setMaxSupply(const QString& maxsupply);
    const void setCryptoCurrency(const QString& cryptocurrency);

private slots:
    void on_back_clicked();

private:
    Ui::CryptoDetailsWindow *ui;
    QObject* controller;
};

#endif // CRYPTODETAILSWINDOW_H
