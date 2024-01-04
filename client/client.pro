QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QUdpSocket
CONFIG   += console
CONFIG += c++17

TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatclient.cpp \
    client.cpp \
    creategroupdialog.cpp \
    groupchatframe.cpp \
    main.cpp \
    mainwindow.cpp \
    registerdialog.cpp \
    userframe.cpp

HEADERS += \
    Response.h \
    chatclient.h \
    client.h \
    creategroupdialog.h \
    groupchatframe.h \
    mainwindow.h \
    registerdialog.h \
    userframe.h

FORMS += \
    chatclient.ui \
    creategroupdialog.ui \
    groupchatframe.ui \
    mainwindow.ui \
    registerdialog.ui \
    userframe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
