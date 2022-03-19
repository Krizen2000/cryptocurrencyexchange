#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QObject>
#include<QString>
#include<string>
#include<vector>

#include"src/events/trendingcryptobuttonclickedevent.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QObject* controller,QWidget *parent = nullptr);
    ~MainWindow();

    const void setTrendingCurrency(std::vector<QString>& trendingcrypto);
    const QString getSearchText() const;

private slots:
    void on_bitcoin_clicked();

    void on_litecoin_clicked();

    void on_ethereum_clicked();

    void on_monero_clicked();

private:
    Ui::MainWindow *ui;
    QObject* controller;
};
#endif // MAINWINDOW_H
