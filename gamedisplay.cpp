#include "gamedisplay.h"

void GameDisplay::InitialPosition(float widtShip, float heightShip)
{
    shipPosition.x=(Game::windowWidth-widtShip)/2;
    shipPosition.y=Game::windowHeight-heightShip;
}

void GameDisplay::changePosition(float widtShip, float heightShip)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shipPosition.x<=(Game::windowWidth-widtShip-20))
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shipPosition.y<=(Game::windowHeight-heightShip-20))
    {
        shipPosition.y=shipPosition.y+20;
    }
}

void GameDisplay::getPosition(float x, float y)
{
    shipPosition.x = x;
    shipPosition.y = y;
}
