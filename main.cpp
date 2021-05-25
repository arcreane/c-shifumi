#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // je tente un push enzo
    // je tente un push jules
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
