#include "gamelogic.h"

GameLogic::GameLogic(sf::RenderWindow &p_window, sf::Sprite &p_background, sf::Sprite &p_ship):m_window(p_window),
                                                                                               m_background(p_background),
                                                                                               m_ship(p_ship)

{

}

void GameLogic::shipControl()
{
    int m_step = 25;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            m_ship.getPosition().x<=(m_window.getSize().x-m_ship.getLocalBounds().width-m_step))
    {
        m_ship.move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_ship.getPosition().x>0)
    {
        m_ship.move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ship.getPosition().y>0)
    {
        m_ship.move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            m_ship.getPosition().y<=(m_window.getSize().y-m_ship.getLocalBounds().height-m_step))
    {
        m_ship.move(0,m_step);
    }
}
