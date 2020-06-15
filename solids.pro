#-------------------------------------------------
#
# Project created by QtCreator 2020-06-15T08:58:51
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = solids
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

CONFIG += C++11


SOURCES += \
        circleobject.cpp \
        geometryobject.cpp \
        geomsettings.cpp \
        main.cpp \
        mainwindow.cpp \
        point2d.cpp \
        rectangleobject.cpp \
        solids.cpp \
        squareobject.cpp \
        triangularobject.cpp \
        view.cpp

HEADERS += \
        circleobject.h \
        geometryobject.h \
        geomsettings.h \
        mainwindow.h \
        point2d.h \
        rectangleobject.h \
        solids.h \
        squareobject.h \
        triangularobject.h \
        view.h

FORMS += \
        mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
