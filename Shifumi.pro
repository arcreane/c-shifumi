QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

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
debug {
    LIBS += -LC:\cygwin64\home\willi\opencv\build\x64\vc15\lib -lopencv_world452d
    INCLUDEPATH += C:\cygwin64\home\willi\opencv\build\include
}
