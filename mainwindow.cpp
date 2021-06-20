#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>



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
    value = ui->pseudoInput->text();
    game.initGame(value, 1);
    ui->welcomeWidget->hide();
    ui->gameWidget->show();
}

void MainWindow::rock()
{
    ui->resultLabel->setText(game.playGame("rock"));
    ui->gameWidget->hide();
    ui->resultWidget->show();
}

void MainWindow::paper()
{
    ui->resultLabel->setText(game.playGame("paper"));
    ui->gameWidget->hide();
    ui->resultWidget->show();
}

void MainWindow::scissors()
{
    ui->resultLabel->setText(game.playGame("scissors"));
    ui->gameWidget->hide();
    ui->resultWidget->show();
}

