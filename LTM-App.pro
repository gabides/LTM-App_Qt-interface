#-------------------------------------------------
#
# Project created by QtCreator 2018-02-04T17:12:43
#
#-------------------------------------------------

QT += core \
    multimedia \
    multimediawidgets \
    widgets

TARGET = LTM-App
TEMPLATE = app

#add OpenCV
LIBS += -L/usr/local/lib

QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
PKGCONFIG += opencv

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



HEADERS = \
    mainwindow.h \
    infoswidget.h \
    videoplayerwidget.h \
    videowidget.h \
    checkablemenu.h \
    algorithmwidget.h

SOURCES = main.cpp \
    mainwindow.cpp \
    infoswidget.cpp \
    videoplayerwidget.cpp \
    videowidget.cpp \
    checkablemenu.cpp \
    algorithmwidget.cpp

DISTFILES +=
