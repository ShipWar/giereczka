#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H
#include "game.h"
#include <SFML/Graphics.hpp>

class GameDisplay
{
public:
    GameDisplay(sf::RenderWindow& p_window, sf::Sprite& p_ship, sf::Sprite& p_background, sf::Sprite &p_shipTwo);
    void displayGame();
    void setInitialPositionForObjects();
private:
    sf::RenderWindow& m_window;
    sf::Sprite& m_background;
    sf::Sprite& m_ship;
    sf::Sprite& m_shipTwo;

};

#endif // GAMEDISPLAY_H

