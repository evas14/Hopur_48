#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T10:31:31
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Verkefni_vika3
TEMPLATE = app

RESOURCES = resource.qrc

SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    connections.cpp \
    datalayer.cpp \
    domainlayer.cpp \
    person.cpp \
    personmenu.cpp \
    computermenu.cpp \
    connectionsmenu.cpp \
    computertable.cpp \
    persontable.cpp


HEADERS  += mainwindow.h \
    computer.h \
    connections.h \
    datalayer.h \
    domainlayer.h \
    person.h \
    personmenu.h \
    computermenu.h \
    connectionsmenu.h \
    computertable.h \
    persontable.h


FORMS    += \
    personmenu.ui \
    computermenu.ui \
    connectionsmenu.ui \
    computertable.ui \
    mainwindow.ui \
    persontable.ui

RESOURCES +=
