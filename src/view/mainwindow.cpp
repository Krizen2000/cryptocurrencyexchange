#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QObject *controller,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->controller = controller;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextbutton_clicked()
{
    QEvent *event = new TokenKeyAcquiredEvent();
    QCoreApplication::sendEvent(controller,event);
    qDebug() << "NextButtonCLickedEvent!!!";
}

QString MainWindow::getTokenKey()
{
    return ui->token->text();
}


const void MainWindow::setTrendingCurrencies(const std::vector<QString> &trendingcrypto)
{
    ui->trend1->setText(trendingcrypto.at(0));
    ui->trend2->setText(trendingcrypto.at(1));
    ui->trend3->setText(trendingcrypto.at(2));
    ui->trend4->setText(trendingcrypto.at(3));
}

const QString MainWindow::getSearchText() const
{
    return ui->searchfield->text();
}

const QString MainWindow::getClickedButtonName() const
{
    return clickedbutton;
}

const void MainWindow::setPrice(const QString &price)
{
    ui->cryptocurrencyprice->setText(price);
}

const void MainWindow::setMarketCap(const QString &marketcap)
{
    ui->cryptocurrencymarketcap->setText(marketcap);
}

const void MainWindow::setMaxSupply(const QString &maxsupply)
{
    ui->cryptocurrencymaxsupply->setText(maxsupply);
}

const void MainWindow::setSymbol(const QString &symbol)
{
    ui->cryptocurrencysymbol->setText(symbol);
}

const void MainWindow::setCryptoCurrency(const QString &cryptocurrency)
{
    ui->cryptocurrencyname->setText(cryptocurrency);
}

const void MainWindow::setDescription(const QString &description)
{
    ui->cryptocurrencydescription->setText(description);
}

const void MainWindow::setCryptoCurrencyImage(const QPixmap *image)
{
    ui->cryptocurrencyimage->setPixmap(*image);
}

const void MainWindow::changeView(const int window)
{
    ui->stackedwindow->setCurrentIndex(window);
}



void MainWindow::on_trend1_clicked()
{
    clickedbutton = ui->trend1->text();
    QEvent *event = new TrendingCryptoButtonClickedEvent();
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_trend2_clicked()
{
    clickedbutton = ui->trend2->text();
    QEvent *event = new TrendingCryptoButtonClickedEvent();
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_trend3_clicked()
{
    clickedbutton = ui->trend3->text();
    QEvent *event = new TrendingCryptoButtonClickedEvent();
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_trend4_clicked()
{
    clickedbutton = ui->trend4->text();
    QEvent *event = new TrendingCryptoButtonClickedEvent();
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_backbutton_clicked()
{
    QEvent *event = new CryptoDetailsBackButtonClickedEvent();
    QCoreApplication::sendEvent(controller,event);
}

