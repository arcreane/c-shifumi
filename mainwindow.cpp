#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->resultWidget->hide();
    ui->gameWidget->hide();

//    cv::VideoCapture capture;

//    capture.open(0);
//    capture.set(cv::CAP_PROP_FRAME_WIDTH, 640);
//    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
//    cv::Mat frame;
//    cv::namedWindow("MainWindow", 1);
//    for(;;){
//        capture>>frame;
//        cv::imshow("MainWindow", frame);
//        //ui->webcam->setPixmap(QPixmap::fromImage(frame));
//        //ui->webcam->setPixmap(QPixmap::fromImage(frame));
//        if( frame.empty() ) break; // end of video stream
//        if( cv::waitKey(10) == 27 ) break; // stop capturing by pressing ESC
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    QString value;
    QString roundMax;
    value = ui->pseudoInput->text();
    roundMax = ui->roundInput->text();
    bool ok = false;
    int nombre = roundMax.toInt(&ok, 10);
    game.initGame(value, nombre);
    ui->welcomeWidget->hide();
    ui->gameWidget->show();
}

void MainWindow::rock()
{
    this->chooseSign(0);
}

void MainWindow::paper()
{
    this->chooseSign(1);
}

void MainWindow::scissors()
{
    this->chooseSign(2);
}

void MainWindow::chooseSign(int sign){
    QString result[2];
    result = std::copy(game.playGame(sign));
    ui->resultLabel->setText(result[0]);
    ui->iaChoice->setText(result[1]);
    ui->gameWidget->hide();
    ui->resultWidget->show();
}

