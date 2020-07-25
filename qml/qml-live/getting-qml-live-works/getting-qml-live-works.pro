QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Компоновка («линковка») с библиотекой QML Live:
INCLUDEPATH += $$[QT_INSTALL_HEADERS]/qmllive
LIBS += -L$$[QT_INSTALL_LIBS] -lqmllive
DEFINES += SRCDIR=\\\"$$PWD/\\\"




# Оператор $$ используется для извлечения содержимого переменной.
# Специальный оператор $$[...] используется для доступа к qmake-свойствам.
# См. https://doc.qt.io/qt-5/qmake-language.html

message(Header files: $$[QT_INSTALL_HEADERS])
# Project MESSAGE: Header files: ~/Qt5.13.0/5.13.0/clang_64/include

message(Libraries: $$[QT_INSTALL_LIBS])
# Project MESSAGE: Libraries: ~/Qt5.13.0/5.13.0/clang_64/lib

HEADERS += \
    qmllive.h
