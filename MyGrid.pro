QT += core gui
QT += widgets

TARGET = MyGrid
TEMPLATE = app

CONFIG += C++11
DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_LFLAGS += -no-pie    // Makes executable runnable on Ubuntu

SOURCES += \
    ColorBox.cpp \
    ColorGrid.cpp \
    main.cpp \
    MyGrid.cpp

HEADERS += \
    ColorBox.h \
    ColorGrid.h \
    MyGrid.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
