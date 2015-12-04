QT += core
QT -= gui
QT += sql

TARGET = Verkefni_vika2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    computer.cpp \
    person.cpp \
    datalayer.cpp \
    ui.cpp \
    connections.cpp

HEADERS += \
    computer.h \
    person.h \
    datalayer.h \
    ui.h \
    connections.h

