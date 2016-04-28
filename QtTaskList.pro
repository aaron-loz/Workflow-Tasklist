#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T22:29:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTaskList
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    addtaskdialog.cpp

HEADERS  += \
    mainwindow.h \
    addtaskdialog.h

FORMS    += \
    tasklist.ui \
    addtaskdialog.ui
