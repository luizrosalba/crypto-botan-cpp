#-------------------------------------------------
#
# Project created by QtCreator 2015-08-14T14:48:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuLogIn
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    botan.cpp \
    DuCrypt.cpp

HEADERS  += dialog.h \
    botan.h \
    DuCrypt.h

FORMS    += dialog.ui

DISTFILES += \
    Botan.pri

include($$PWD/Botan.pri)

QMAKE_CXXFLAGS += -std=gnu++14
