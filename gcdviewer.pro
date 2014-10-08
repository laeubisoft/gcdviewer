#-------------------------------------------------
#
# Project created by QtCreator 2014-04-08T13:41:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gcdviewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileproxy.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    fileproxy.h \
    qcustomplot.h

FORMS    += mainwindow.ui
