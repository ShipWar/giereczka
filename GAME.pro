TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    gamedisplay.cpp \
    gamelogic.cpp
INCLUDEPATH += /usr/include/SFML
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    game.h \
    gamedisplay.h \
    gamelogic.h


