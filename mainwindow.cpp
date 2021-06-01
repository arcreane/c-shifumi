#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    capture.open(0);
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cv::Mat frame;
    cv::namedWindow("MainWindow", 1);
    for(;;){
        capture>>frame;
        cv::imshow("MainWindow", frame);
        if( frame.empty() ) break; // end of video stream
        if( cv::waitKey(10) == 27 ) break; // stop capturing by pressing ESC
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

