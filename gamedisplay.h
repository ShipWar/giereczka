#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H
#include "game.h"
#include <SFML/Graphics.hpp>

class GameDisplay
{
public:
    GameDisplay(sf::RenderWindow& p_window, sf::Sprite& p_background, sf::Sprite& p_firstShip, sf::Sprite &p_secoundShip);
    ~GameDisplay();
    void displayGame();
    void setInitialPositionForObjects();
private:
    sf::RenderWindow& m_window;
    sf::Sprite& m_background;
    sf::Sprite& m_firstShip;
    sf::Sprite& m_secoundShip;

};

#endif // GAMEDISPLAY_H

