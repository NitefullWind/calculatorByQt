#-------------------------------------------------
#
# Project created by QtCreator 2014-09-28T08:41:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stack.cpp

HEADERS  += mainwindow.h \
    stack.h

FORMS    += mainwindow.ui
