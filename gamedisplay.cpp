#include "gamedisplay.h"

GameDisplay::GameDisplay()
{

}

void GameDisplay::displayGame(sf::RenderWindow &p_window, sf::Sprite &p_background, sf::Sprite p_ship)
{
    p_window.clear();
    p_window.draw(p_background);
    p_window.draw(p_ship);
    p_window.display();
}
