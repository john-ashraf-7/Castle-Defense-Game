QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    astar.cpp \
    bullet.cpp \
    cannon.cpp \
    castle.cpp \
    fences.cpp \
    levels.cpp \
    main.cpp \
    mainmenu.cpp \
    market.cpp \
    object.cpp \
    registerwindow.cpp \
    result.cpp \
    troops.cpp \
    win.cpp

HEADERS += \
    astar.h \
    bullet.h \
    cannon.h \
    castle.h \
    fences.h \
    levels.h \
    mainmenu.h \
    market.h \
    object.h \
    registerwindow.h \
    result.h \
    troops.h \
    win.h

FORMS += \
    mainmenu.ui \
    market.ui \
    registerwindow.ui \
    result.ui \
    win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
