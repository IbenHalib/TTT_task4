#-------------------------------------------------
#
# Project created by QtCreator 2013-10-17T23:14:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    focker.cpp

HEADERS  += mainwindow.h \
    focker.h

FORMS    += mainwindow.ui
include(qwt.pri)
