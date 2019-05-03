#-------------------------------------------------
#
# Project created by QtCreator 2019-04-14T14:40:13
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = computer-assembly
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    about.cpp \
    computercomponent.cpp \
    videocard.cpp \
    motherboard.cpp \
    hdd.cpp \
    cpu.cpp \
    powersupply.cpp \
    ram.cpp \
    csvdata.cpp \
    appmodel.cpp \
    print.cpp \
    multiple.cpp \
    tabform.cpp

HEADERS += \
        mainwindow.h \
    about.h \
    computercomponent.h \
    videocard.h \
    motherboard.h \
    hdd.h \
    cpu.h \
    powersupply.h \
    ram.h \
    csvdata.h \
    devicetypes.h \
    appmodel.h \
    print.h \
    multiple.h \
    tabform.h

FORMS += \
        mainwindow.ui \
    about.ui \
    print.ui \
    multiple.ui \
    tabform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    myapp.rc

RC_FILE = myapp.rc
