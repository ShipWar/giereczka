TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Source/game.cpp \
    Source/player.cpp \
    Source/grid.cpp \
    Source/bullet.cpp \
    Source/idraw.cpp \
    Source/mesurments.cpp \
    Source/achivement.cpp


INCLUDEPATH += /usr/include/SFML
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


HEADERS += \
    Include/game.h \
    Include/player.h \
    Include/grid.h \
    Include/bullet.h \
    Include/idraw.h \
    Include/mesurments.h \
    Include/achivement.h
