#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <SFML/Graphics.hpp>

class GameLogic
{
public:
    GameLogic(sf::RenderWindow& p_window, sf::Sprite& p_background, sf::Sprite& p_ship);
    void shipControl();
private:
    sf::RenderWindow& m_window;
    sf::Sprite& m_background;
    sf::Sprite& m_ship;



};

#endif // GAMELOGIC_H
