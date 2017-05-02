#include "gamelogic.h"


void GameLogic::InitialPosition(float widtShip, float heightShip, const int windowWidth, const int windowHeight)
{
    shipPosition.x=(windowWidth-widtShip)/2;
    shipPosition.y=windowHeight-heightShip;
}

void GameLogic::changePosition(float widtShip, float heightShip, const int p_windowWidth, const int p_windowHeight)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shipPosition.x<=(p_windowWidth-widtShip-20))
    {
        shipPosition.x=shipPosition.x+20;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shipPosition.x>0)
    {
        shipPosition.x=shipPosition.x-20;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shipPosition.y>0)
    {
        shipPosition.y=shipPosition.y-20;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shipPosition.y<=(p_windowHeight-heightShip-20))
    {
        shipPosition.y=shipPosition.y+20;
    }
}

void GameLogic::getPosition(float x, float y)
{
    shipPosition.x = x;
    shipPosition.y = y;
}
