#include "cryptodetailswindow.h"
#include "ui_cryptodetailswindow.h"

CryptoDetailsWindow::CryptoDetailsWindow(QObject* controller,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CryptoDetailsWindow)
{
    ui->setupUi(this);
    this->controller = controller;
}

CryptoDetailsWindow::~CryptoDetailsWindow()
{
    delete ui;
}

const void CryptoDetailsWindow::setPrice(const QString& price)
{
    ui->price->setText(price);
}

const void CryptoDetailsWindow::setMarketCap(const QString &marketcap)
{
    ui->marketcap->setText(marketcap);
}

const void CryptoDetailsWindow::setMaxSupply(const QString &maxsupply)
{
    ui->maxsupply->setText(maxsupply);
}

const void CryptoDetailsWindow::setCryptoCurrency(const QString &cryptocurrency)
{
    ui->cryptocurrencyname->setText(cryptocurrency);
}

void CryptoDetailsWindow::on_back_clicked()
{
    QEvent* event = new CryptoDetailsBackButtonClickedEvent();
    QCoreApplication::sendEvent(controller,event);
}

