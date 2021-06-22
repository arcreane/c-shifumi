#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->resultWidget->hide();
    ui->gameWidget->hide();
    ui->endWidget->hide();

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
    ui->endWidget->hide();
    ui->gameWidget->show();
    this->game.playerOne.nbLoses = 0;
    this->game.playerOne.nbWins = 0;
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
    std::vector<std::string> result (2);
    result = game.playGame(sign);
    ui->resultLabel->setText(QString(result[0].c_str()));
    ui->iaChoice->setText(QString(result[1].c_str()));
    ui->gameWidget->hide();
    ui->resultWidget->show();
    QTimer::singleShot(2000 , [=]() {
        if(this->game.maxRound == this->game.playerOne.nbWins){
            ui->resultWidget->hide();
            ui->endWidget->show();
            ui->endMessage->setText("Vous avez gagné");
        }
        else if(this->game.maxRound == this->game.playerOne.nbLoses){
             ui->resultWidget->hide();
             ui->endWidget->show();
             ui->endMessage->setText("Vous avez perdu");
        }
        else{
            ui->gameWidget->show();
            ui->resultWidget->hide();
        }
    });

}

