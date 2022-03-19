#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include<QWidget>
#include<QString>
#include<vector>
#include<array>
#include<string>

#include"src/view/tokenwindow/tokenwindow.h"
#include"src/view/mainwindow/mainwindow.h"
#include"src/view/cryptodetailswindow/cryptodetailswindow.h"

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

    // Class CryptoDetailsWindow
    const void setPrice(const std::string& price);
    const void setMarketCap(const std::string& marketcap);
    const void setMaxSupply(const std::string& maxsupply);
    const void setCryptoCurrency(const std::string& cryptocurrency);

private:
    explicit View(QObject* controller);

    std::array<QWidget*,3> viewclasses;
    QWidget* currentview;

    QObject* controller;
};

//View* View::instance = 0;
//QApplication* View::application = 0;

#endif // VIEW_H
