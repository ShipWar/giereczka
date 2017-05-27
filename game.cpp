#include "game.h"
#include"grid.h"
#include"player.h"

GAME::GAME()
{
    m_window.create(sf::VideoMode(windowWidth,windowHeight, 16), "SHIPS WARSS");

   std::vector<sf::Keyboard::Key> l_vecA = {sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Space};
   std::vector<sf::Keyboard::Key> l_vecB = {sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::Tab};

    m_firstPlayer = new Player("DurrrSpaceShip.png", "Gracz Dolny", l_vecA, sf::Vector2f(windowWidth/2,windowHeight-100));
    m_secondPlayer = new Player("spikedShip.png", "Gracz Gorny", l_vecB, sf::Vector2f(windowWidth/2, 0));
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

            if(m_firstPlayer->isAlive() && m_secondPlayer->isAlive())
            {
                m_firstPlayer->shipControl();
                m_secondPlayer->shipControl();
            }
        }

        if(m_firstPlayer->isAlive() && m_secondPlayer->isAlive())
        {
            m_firstPlayer->shoot(sf::Vector2f(0,-10));
            m_secondPlayer->shoot(sf::Vector2f(0, 10));
            m_firstPlayer->getShoot(m_secondPlayer->getBullet());
            m_secondPlayer->getShoot(m_firstPlayer->getBullet());
        }
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

void GAME::closeWindow(sf::Event& p_event)
{
    if (p_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        m_window.close();
}
