#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <vector>
#include "src/events/tokenkeyacquiredevent.hpp"
#include"src/events/cryptodetailsbackbuttonclickedevent.hpp"
#include "src/events/trendingcryptobuttonclickedevent.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QObject *controller,QWidget *parent = nullptr);
    ~MainWindow();


    QString getTokenKey();

    const void setTrendingCurrencies(const std::vector<QString> &trendingcrypto);
    const QString getSearchText() const; // Future use

    const QString getClickedButtonName() const;


    const void setPrice(const QString &price);
    const void setMarketCap(const QString &marketcap);
    const void setMaxSupply(const QString &maxsupply);
    const void setSymbol(const QString &symbol);
    const void setCryptoCurrency(const QString &cryptocurrency);
    const void setDescription(const QString &description);
    const void setCryptoCurrencyImage(const QPixmap *image);

    const void changeView(const int window);

private slots:

    void on_nextbutton_clicked();

    void on_trend1_clicked();
    void on_trend2_clicked();
    void on_trend3_clicked();
    void on_trend4_clicked();

    void on_backbutton_clicked();

private:

    Ui::MainWindow *ui;
    QObject *controller;
    QString clickedbutton;

};

#endif // MAINWINDOW_H
