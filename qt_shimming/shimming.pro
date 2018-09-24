#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T15:13:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shimming
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileshimming.cpp \
    tableshimming.cpp \
    rs232.cpp

HEADERS  += mainwindow.h \
    fileshimming.h \
    tableshimming.h \
    rs232.h

FORMS    += mainwindow.ui

#include("/home/optimus/Documentos/qtSourceCode/qextserialport-1.2rc/src/qextserialport.pri")
include("/home/optimus/Documents/qtSourceCode/qextserialport-1.2rc/src/qextserialport.pri")
