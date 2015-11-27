QT += core
QT -= gui

TARGET = Verkefni_vika1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    ui.cpp \
    datalayer.cpp

HEADERS += \
    person.h \
    ui.h \
    datalayer.h

