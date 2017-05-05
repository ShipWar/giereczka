#include "gamelogic.h"

GameLogic::GameLogic(sf::RenderWindow &p_window, sf::Sprite &p_ship, sf::Sprite &p_shipTwo):m_window(p_window)


{
    m_playerOne = new Player(p_ship);
    m_playerTwo = new Player(p_shipTwo);
}

GameLogic::~GameLogic()
{
    delete m_playerOne;
    delete m_playerTwo;
}

void GameLogic::shipsControl()
{
    int m_step = 25;

    //FirstPlayer

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            m_playerOne->getSprite().getPosition().x<=(m_window.getSize().x-m_playerOne->getSprite().getLocalBounds().width-m_step))
    {
        m_playerOne->move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_playerOne->getSprite().getPosition().x>0)
    {
        m_playerOne->move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_playerOne->getSprite().getPosition().y>0)
    {
        m_playerOne->move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            m_playerOne->getSprite().getPosition().y<=(m_window.getSize().y-m_playerOne->getSprite().getLocalBounds().height-m_step))
    {
        m_playerOne->move(0,m_step);
    }

    //SecoundPlayer

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
            m_playerTwo->getSprite().getPosition().x<=(m_window.getSize().x-m_playerTwo->getSprite().getLocalBounds().width-m_step))
    {
        m_playerTwo->move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_playerTwo->getSprite().getPosition().x>0)
    {
        m_playerTwo->move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_playerTwo->getSprite().getPosition().y>0)
    {
        m_playerTwo->move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            m_playerTwo->getSprite().getPosition().y<=(m_window.getSize().y-m_playerTwo->getSprite().getLocalBounds().height-m_step))
    {
        m_playerTwo->move(0,m_step);
    }
}

