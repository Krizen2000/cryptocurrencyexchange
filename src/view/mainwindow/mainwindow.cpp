#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QObject* controller,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->controller = controller;
}

MainWindow::~MainWindow()
{
    delete ui;
}

const void MainWindow::setTrendingCurrency(std::vector<QString> &trendingcrypto)
{
    ui->bitcoin->setText(trendingcrypto[0]);
    ui->litecoin->setText(trendingcrypto[1]);
    ui->ethereum->setText(trendingcrypto[2]);
    ui->monero->setText(trendingcrypto[3]);
}

const QString MainWindow::getSearchText() const
{
    return ui->searchfield->text();
}


void MainWindow::on_bitcoin_clicked()
{
    QEvent* event = new TrendingCryptoButtonClickedEvent(std::string("bitcoin"));
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_litecoin_clicked()
{
    QEvent * event = new TrendingCryptoButtonClickedEvent(std::string("litecoin"));
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_ethereum_clicked()
{
    QEvent * event = new TrendingCryptoButtonClickedEvent(std::string("ethereum"));
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_monero_clicked()
{
    QEvent * event = new TrendingCryptoButtonClickedEvent(std::string("monero"));
    QCoreApplication::sendEvent(controller,event);
}
