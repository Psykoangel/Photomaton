#-------------------------------------------------
#
# Project created by QtCreator 2016-07-09T15:39:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += multimedia multimediawidgets

TARGET = Photomaton
TEMPLATE = app


SOURCES += src/main.cpp\
           src/mainwindow.cpp

HEADERS  += src/mainwindow.h

FORMS    += src/gui/mainwindow.ui

RESOURCES += \
    resource/resources.qrc
