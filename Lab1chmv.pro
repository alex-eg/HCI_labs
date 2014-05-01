#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T20:27:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab1chmv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    digitsdemonstrator.cpp \
    abstractstylednumberrenderer.cpp \
    arabnumsrenderer.cpp \
    testgenerator.cpp

HEADERS  += mainwindow.h \
    digitsdemonstrator.h \
    labapi.h \
    abstractstylednumberrenderer.h \
    arabnumsrenderer.h \
    testgenerator.h

FORMS    += mainwindow.ui \
    digitsdemonstrator.ui
