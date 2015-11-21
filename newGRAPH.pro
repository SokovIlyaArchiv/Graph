#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T00:03:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newGRAPH
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    graph.cpp \
    search.cpp \
    depthfirstsearch.cpp

HEADERS  += mainwindow.h \
    vertex.h \
    point.h \
    graph.h \
    search.h \
    depthfirstsearch.h
