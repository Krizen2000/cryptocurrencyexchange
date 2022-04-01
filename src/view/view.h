#ifndef VIEW_H
#define VIEW_H

#include<QObject>
#include<QWidget>
#include<QMessageBox>
#include<QString>
#include<vector>
#include<array>
#include<string>
#include<QPixmap>

#include"src/view/mainwindow.h"

class View : public QObject
{
    Q_OBJECT
public:

    static View *getInstance(QObject *controller);

    enum Window {
        TOKENWINDOW,
        MAINWINDOW,
        CRYPTODETAILSWINDOW,
    };
    const void changeView(Window windownum) const;

    // Class TokenWindow
    const std::string getTokenKeyFromView() const;

    // Class MainWindow
    const void setTrendingCurrencies(const std::vector<std::string> &trendingcrypto) const;
    const std::string getSearchText() const;
    const std::string getClickedButton() const;

    // Class CryptoDetailsWindow
    const void setPrice(const std::string &price) const;
    const void setMarketCap(const std::string &marketcap) const;
    const void setMaxSupply(const std::string &maxsupply) const;
    const void setSymbol(const std::string &symbol) const;
    const void setCryptoCurrency(const std::string &cryptocurrency) const;
    const void setDescription(const std::string &description) const;
    const void setCryptoCurrencyImage(const QPixmap *image) const;

    const void displayErrorMessageBox(const std::string &errmsg) const;

private:

    explicit View(QObject *controller);

    MainWindow *mainwindow;
    QObject *controller;

};


#endif // VIEW_H
