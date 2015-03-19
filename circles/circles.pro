CONFIG += c++11
TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    circle.cpp \
    flyingspot.cpp \
    maincontroller.cpp \
    appdatamodel.cpp \
    gamedatamodel.cpp \
    gamecontroller.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    circle.h \
    flyingspot.h \
    maincontroller.h \
    appdatamodel.h \
    gamedatamodel.h \
    gamecontroller.h
