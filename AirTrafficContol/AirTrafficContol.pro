#-------------------------------------------------
#
# Project created by QtCreator 2018-12-13T12:19:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirTrafficContol
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# QXlsx code for Application Qt project
QXLSX_PARENTPATH= ./QXlsx/         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH= ./QXlsx/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH= ./QXlsx/source/  # current QXlsx source path is ./source/
include(./QXlsx/QXlsx.pri)


SOURCES += \
        main.cpp \
        splashscreen.cpp \
    mainwindow.cpp \
    CustomWidgets/draggablelabel.cpp \
    CustomWidgets/togglebutton.cpp \
    Graph/graph.cpp \
    CustomWidgets/limitedtimer.cpp

HEADERS += \
        splashscreen.h \
    mainwindow.h \
    Graph/Graph.h \
    CustomWidgets/draggablelabel.h \
    CustomWidgets/togglebutton.h \
    CustomWidgets/style.h \
    LinkedList/LinkedList.h \
    CustomWidgets/limitedtimer.h

FORMS += \
        splashscreen.ui \
    mainwindow.ui
