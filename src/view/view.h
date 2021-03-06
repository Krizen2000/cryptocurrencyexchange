#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include<QWidget>
#include<QMessageBox>
#include<QString>
#include<vector>
#include<array>
#include<string>
#include <QPixmap>

#include"src/view/mainwindow.h"

class View : public QObject
{
    Q_OBJECT
public:
    static View *getInstance(QObject* controller);

    enum Window {
        TOKENWINDOW,
        MAINWINDOW,
        CRYPTODETAILSWINDOW,
    };


    const void changeView(Window windownum);

    // Class TokenWindow
    const std::string getTokenKeyFromView() const;

    // Class MainWindow
    const void setTrendingCurrencies(std::vector<std::string>& trendingcrypto);
    const std::string getSearchText() const;
    const std::string getClickedButton() const;

    // Class CryptoDetailsWindow
    const void setPrice(std::string price);
    const void setMarketCap(std::string marketcap);
    const void setMaxSupply(std::string maxsupply);
    const void setSymbol(std::string symbol);
    const void setCryptoCurrency(std::string cryptocurrency);
    const void setDescription(std::string description);
    const void setCryptoCurrencyImage(QPixmap* image);

    const void displayErrorMessageBox(const std::string& errmsg) const;

private:

    explicit View(QObject* controller);

//    std::array<QWidget*,3> viewclasses;
//    QWidget* currentview;
    MainWindow* mainwindow;

    QObject* controller;
};

//View* View::instance = 0;
//QApplication* View::application = 0;

#endif // VIEW_H
