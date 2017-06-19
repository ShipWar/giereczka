TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    grid.cpp \
    bullet.cpp \
    idraw.cpp \
    mesurments.cpp \
    achivement.cpp


INCLUDEPATH += /usr/include/SFML
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


HEADERS += \
    game.h \
    player.h \
    grid.h \
    bullet.h \
    idraw.h \
    mesurments.h \
    achivement.h
