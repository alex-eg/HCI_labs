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
            stylednums/stylednumberrenderer.cpp \
            stylednums/arabnumsrenderer.cpp \
        testgenerator.cpp \
        testanswerschooser.cpp \
    stylednums/romenumsrenderer.cpp \
    stylednums/wordpresentationnumsrenderer.cpp \
    stylednums/symbolicpresentationnumersrenderer.cpp \
    statistics/statistics.cpp \
    statisticswidget.cpp \
    pieview.cpp \
    statisticsmodel.cpp \
    statistics/totalstatistics.cpp \
    statistics/statisticsaggregator.cpp

HEADERS  += mainwindow.h \
    digitsdemonstrator.h \
        stylednums/stylednumsapi.h \
        stylednums/stylednumberrenderer.h \
        stylednums/arabnumsrenderer.h \
    testgenerator.h \
    testanswerschooser.h \
    stylednums/stylednumberrenderer.h \
    stylednums/romenumsrenderer.h \
    stylednums/wordpresentationnumsrenderer.h \
    stylednums/symbolicpresentationnumersrenderer.h \
    statistics/statistics.h \
    statisticswidget.h \
    pieview.h \
    statisticsmodel.h \
    statistics/totalstatistics.h \
    statistics/statisticsaggregator.h \
    statistics/statisticsapi.h

FORMS    += mainwindow.ui \
    digitsdemonstrator.ui \
    testanswerschooser.ui \
    statisticswidget.ui
