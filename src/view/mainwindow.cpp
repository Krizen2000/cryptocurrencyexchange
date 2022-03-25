#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QObject* controller,QWidget *parent) :
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
    QEvent* eventd = new TokenKeyAcquiredEvent();         // Needs more work
    QCoreApplication::sendEvent(controller,eventd);
    qDebug() << "NextButtonCLickedEvent!!!";
}

QString MainWindow::getTokenKey()
{
    return ui->token->text();
}


const void MainWindow::setTrendingCurrencies(std::vector<QString> &trendingcrypto)
{
    ui->trend1->setText(trendingcrypto[0]);
    ui->trend2->setText(trendingcrypto[1]);
    ui->trend3->setText(trendingcrypto[2]);
    ui->trend4->setText(trendingcrypto[3]);
}

const QString MainWindow::getSearchText() const
{
    return ui->searchfield->text();
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

const void MainWindow::setCryptoCurrency(const QString &cryptocurrency)
{
    ui->cryptocurrencyname->setText(cryptocurrency);
}

const void MainWindow::setDescription(const QString& description)
{
    ui->cryptocurrencydescription->setText(description);
}

const void MainWindow::setCryptoCurrencyImage(const QPixmap *image)
{
    ui->cryptocurrencyname->setPixmap(*image);
}

const void MainWindow::changeView(int window)
{
    ui->stackedwindow->setCurrentIndex(window);
}



void MainWindow::on_trend1_clicked()
{
    QEvent * event = new TrendingCryptoButtonClickedEvent(ui->trend1->text().toStdString());
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_trend2_clicked()
{
    QEvent * event = new TrendingCryptoButtonClickedEvent(ui->trend2->text().toStdString());
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_trend3_clicked()
{
    QEvent * event = new TrendingCryptoButtonClickedEvent(ui->trend3->text().toStdString());
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_trend4_clicked()
{
    QEvent * event = new TrendingCryptoButtonClickedEvent(ui->trend4->text().toStdString());
    QCoreApplication::sendEvent(controller,event);
}


void MainWindow::on_backbutton_clicked()
{
    QEvent* event = new CryptoDetailsBackButtonClickedEvent();
    QCoreApplication::sendEvent(controller,event);
}

