#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include "opencv2/opencv.hpp"
#include <opencv2/highgui.hpp>
#include <QPixmap>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    cv::VideoCapture capture;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
