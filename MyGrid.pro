QT += core gui
QT += widgets

TARGET = MyGrid
TEMPLATE = app

CONFIG += C++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    MyGrid.cpp

HEADERS += \
    MyGrid.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
