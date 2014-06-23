#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T14:01:37
#
#-------------------------------------------------
QT       += core gui declarative
CONFIG +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport
INCLUDEPATH+=/home/coala/Qt/5.3/gcc_64/include
TARGET = KInt
TEMPLATE = app


SOURCES += main.cpp\
    kompas.cpp \
    mainwindow.cpp \
    kompassettings.cpp \
    skldialog.cpp

HEADERS  += \
    kompas.h \
    mainwindow.h \
    kompassettings.h \
    skldialog.h

OTHER_FILES += \
    main.qml \
    Kompas.qml

RESOURCES += \
    res.qrc

FORMS += \
    kompasdialog.ui \
    mainwindow.ui \
    kompassettings.ui \
    skldialog.ui
