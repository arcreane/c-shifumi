#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // je tente un push enzo
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
