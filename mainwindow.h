#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void startGame();
    void rock();
    void paper();
    void scissors();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void chooseSign(int sign);
    Game game;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
