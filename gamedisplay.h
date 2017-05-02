#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H
#include "game.h"
#include <SFML/Graphics.hpp>

class GameDisplay
{
public:
    GameDisplay();
    void displayGame(sf::RenderWindow& p_window, sf::Sprite& p_background, sf::Sprite p_ship);
};

#endif // GAMEDISPLAY_H
