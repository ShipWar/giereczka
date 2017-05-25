TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    grid.cpp \
    bullet.cpp


INCLUDEPATH += /usr/include/SFML
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    game.h \
    player.h \
    grid.h \
    idrawinterface.h \
    bullet.h
