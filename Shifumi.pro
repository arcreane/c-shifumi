QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


QT_CONFIG -= no-pkg-config
CONFIG  += link_pkgconfig
PKGCONFIG += opencv4

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    gameengine.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp

HEADERS += \
    game.h \
    gameengine.h \
    mainwindow.h \
    player.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

macx {
    INCLUDEPATH += "/usr/local/Cellar/opencv/4.5.2_4/include/opencv4"
    LIBS += -L"/usr/local/Cellar/opencv/4.5.2_4/lib"
}
