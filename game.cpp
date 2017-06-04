#include "game.h"
#include"grid.h"
#include"player.h"

GAME::GAME()
{
    m_window.create(sf::VideoMode(windowWidth,windowHeight, 16), "SHIPS WARSS");

   std::map<std::string, sf::Keyboard::Key> l_mapA = {{"R",sf::Keyboard::Right},
                                                      {"L",sf::Keyboard::Left},
                                                      {"U",sf::Keyboard::Up},
                                                      {"D",sf::Keyboard::Down},
                                                      {"Fire",sf::Keyboard::Space}};
   std::map<std::string, sf::Keyboard::Key> l_mapB = {{"R",sf::Keyboard::D},
                                                      {"L",sf::Keyboard::A},
                                                      {"U",sf::Keyboard::W},
                                                      {"D",sf::Keyboard::S},
                                                      {"Fire",sf::Keyboard::Tab}};

    m_firstPlayer = new Player("DurrrSpaceShip.png", "Gracz Dolny", l_mapA);
    m_secondPlayer = new Player("ship2.png", "Gracz Gorny", l_mapB);
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
        }

        if(m_firstPlayer->isAlive() && m_secondPlayer->isAlive())
        {
            m_firstPlayer->shipControl();
            m_secondPlayer->shipControl();
            m_firstPlayer->shoot();
            m_secondPlayer->shoot();
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
        if(element->isVisible())
            m_window.draw(element->getSprite());
    }

    m_window.display();
}

void GAME::closeWindow(sf::Event& p_event)
{
    if (p_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        m_window.close();
}
