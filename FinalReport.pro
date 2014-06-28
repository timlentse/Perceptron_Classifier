#-------------------------------------------------
#
# Project created by QtCreator 2014-06-10T15:43:00
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = FinalReport
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    MyFunction.cpp
INCLUDEPATH += /usr/include/opencv2

LIBS += -L/usr/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui

HEADERS += \
    MyFunction.h
