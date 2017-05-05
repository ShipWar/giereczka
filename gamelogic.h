#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <SFML/Graphics.hpp>
#include "player.h"

class GameLogic
{
public:
    GameLogic(sf::RenderWindow& p_window, sf::Sprite& p_firstShip, sf::Sprite &p_secoundShip);
    ~GameLogic();
    void shipsControl();
private:
    sf::RenderWindow& m_window;
    Player *m_firstPlayer;
    Player *m_secoundPlayer;
};

#endif // GAMELOGIC_H
