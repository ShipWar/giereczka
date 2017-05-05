#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <SFML/Graphics.hpp>
#include "player.h"

class GameLogic
{
public:
    GameLogic(sf::RenderWindow& p_window, sf::Sprite& p_ship, sf::Sprite &p_shipTwo);
    ~GameLogic();
    void shipsControl();
private:
    sf::RenderWindow& m_window;
    Player *m_playerOne;
    Player *m_playerTwo;


};

#endif // GAMELOGIC_H
