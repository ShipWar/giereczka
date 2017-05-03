#include "gamelogic.h"


void GameLogic::InitialPosition(sf::RenderWindow &p_window, sf::Texture p_texture)
{
    shipPosition.x=(p_window.getSize().x-p_texture.getSize().x)/2;
    shipPosition.y=p_window.getSize().y-p_texture.getSize().y;
}

void GameLogic::shipControl(sf::Event p_event, sf::RenderWindow &p_window, sf::Texture p_texture, sf::Sprite p_ship)
 {
    const int step=20;

    if(p_event.type == sf::Event::KeyPressed)
    {
        if(p_event.key.code == sf::Keyboard::Up && p_ship.getPosition().y>0)
        {
           p_ship.setPosition(p_ship.getPosition().x, p_ship.getPosition().y-step);
        }
        if(p_event.key.code == sf::Keyboard::Down && p_ship.getPosition().y<=(p_window.getSize().y-p_texture.getSize().y-step))
        {
            p_ship.setPosition(p_ship.getPosition().x, p_ship.getPosition().y+step);
        }
        if(p_event.key.code == sf::Keyboard::Left && p_ship.getPosition().x>0)
        {
            p_ship.setPosition(p_ship.getPosition().x-step, p_ship.getPosition().y);
        }
        if(p_event.key.code == sf::Keyboard::Right && p_ship.getPosition().x<=(p_window.getSize().x-p_texture.getSize().x-step))
        {
            p_ship.setPosition(p_ship.getPosition().x+step, p_ship.getPosition().y);
        }
        shipPosition=p_ship.getPosition();
    }
 }

