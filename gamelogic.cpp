#include "gamelogic.h"

GameLogic::GameLogic(sf::RenderWindow &p_window, sf::Sprite &p_firstShip, sf::Sprite &p_secoundShip):m_window(p_window)
{
    m_firstPlayer = new Player(p_firstShip);
    m_secoundPlayer = new Player(p_secoundShip);
}

GameLogic::~GameLogic()
{
    delete m_firstPlayer;
    delete m_secoundPlayer;
}

void GameLogic::shipsControl()
{
    int m_step = 25;

    //FirstPlayer

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            m_firstPlayer->getSprite().getPosition().x<=(m_window.getSize().x-m_firstPlayer->getSprite().getLocalBounds().width-m_step))
    {
        m_firstPlayer->move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_firstPlayer->getSprite().getPosition().x>0)
    {
        m_firstPlayer->move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_firstPlayer->getSprite().getPosition().y>0)
    {
        m_firstPlayer->move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            m_firstPlayer->getSprite().getPosition().y<=(m_window.getSize().y-m_firstPlayer->getSprite().getLocalBounds().height-m_step))
    {
        m_firstPlayer->move(0,m_step);
    }

    //SecoundPlayer

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
            m_secoundPlayer->getSprite().getPosition().x<=(m_window.getSize().x-m_secoundPlayer->getSprite().getLocalBounds().width-m_step))
    {
        m_secoundPlayer->move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_secoundPlayer->getSprite().getPosition().x>0)
    {
        m_secoundPlayer->move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_secoundPlayer->getSprite().getPosition().y>0)
    {
        m_secoundPlayer->move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            m_secoundPlayer->getSprite().getPosition().y<=(m_window.getSize().y-m_secoundPlayer->getSprite().getLocalBounds().height-m_step))
    {
        m_secoundPlayer->move(0,m_step);
    }
}

