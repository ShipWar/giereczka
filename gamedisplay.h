#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H
#include "game.h"

class GameDisplay
{
public:
    void InitialPosition(float widtShip, float heightShip);
    void changePosition(float widtShip, float heightShip);
    void getPosition(float x, float y);
    sf::Vector2u shipPosition;
};

#endif // GAMEDISPLAY_H
