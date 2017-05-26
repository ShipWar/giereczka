#include "game.h"
#include"grid.h"
#include"player.h"

GAME::GAME()
{
    m_window.create(sf::VideoMode(windowWidth,windowHeight, 16), "SHIPS WARSS");

    m_firstPlayer = new Player("DurrrSpaceShip.png");
    m_secondPlayer = new Player("spikedShip.png");
    m_grid = new Grid("space.jpg");

    m_vectorOfDrawableElemnts={m_grid, m_firstPlayer, m_secondPlayer, m_firstPlayer->getBullet(), m_secondPlayer->getBullet()};
}

GAME::~GAME()
{
    delete m_firstPlayer;
    delete m_secondPlayer;
    delete m_grid;
}

void GAME::mainLoop()
{
    while (m_window.isOpen())
    {
        sf::Event l_event;
        while (m_window.pollEvent(l_event))
        {
            closeWindow(l_event);
            shipsControl();
        }
        m_firstPlayer->shoot(sf::Vector2f(0,-10));
        m_secondPlayer->shoot(sf::Vector2f(0, 10));
        m_firstPlayer->getShoot(m_secondPlayer->getBullet());
        m_secondPlayer->getShoot(m_firstPlayer->getBullet());
       display();
    }
}

void GAME::display()
{

    for(IDraw* element : m_vectorOfDrawableElemnts)
    {
        if(element->isVisible)
            m_window.draw(element->getSprite());
    }

    m_window.display();
}

void GAME::shipsControl()
{
    int m_step = 25;

    //FirstPlayer

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            m_firstPlayer->getSprite().getPosition().x<=(m_window.getSize().x-m_firstPlayer->getSprite().getLocalBounds().width-m_step))
    {
        m_firstPlayer->getSprite().move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_firstPlayer->getSprite().getPosition().x>0)
    {
        m_firstPlayer->getSprite().move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_firstPlayer->getSprite().getPosition().y>0)
    {
        m_firstPlayer->getSprite().move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            m_firstPlayer->getSprite().getPosition().y<=(m_window.getSize().y-m_firstPlayer->getSprite().getLocalBounds().height-m_step))
    {
        m_firstPlayer->getSprite().move(0,m_step);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(not m_firstPlayer->getBullet()->isVisible)
        {
            m_firstPlayer->getBullet()->getSprite().setPosition(m_firstPlayer->getSprite().getPosition());
            m_firstPlayer->getBullet()->isVisible = true;
        }
    }

    //SecoundPlayer

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
            m_secondPlayer->getSprite().getPosition().x<=(m_window.getSize().x-m_secondPlayer->getSprite().getLocalBounds().width-m_step))
    {
        m_secondPlayer->getSprite().move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_secondPlayer->getSprite().getPosition().x>0)
    {
        m_secondPlayer->getSprite().move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_secondPlayer->getSprite().getPosition().y>0)
    {
        m_secondPlayer->getSprite().move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
            m_secondPlayer->getSprite().getPosition().y<=(m_window.getSize().y-m_secondPlayer->getSprite().getLocalBounds().height-m_step))
    {
        m_secondPlayer->getSprite().move(0,m_step);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
    {
        if(not m_secondPlayer->getBullet()->isVisible)
        {
            m_secondPlayer->getBullet()->getSprite().setPosition(m_secondPlayer->getSprite().getPosition());
            m_secondPlayer->getBullet()->isVisible = true;
        }
    }


}

void GAME::closeWindow(sf::Event& p_event)
{
    if (p_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        m_window.close();
}
