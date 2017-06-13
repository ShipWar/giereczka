#include "game.h"
#include "grid.h"
#include "player.h"



GAME::GAME()
{
    m_window.create(sf::VideoMode(m_windowSize.first, m_windowSize.second, 16), "SHIPS WARSS");



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

    m_firstPlayer = std::make_unique<Player>("DurrrSpaceShip.png", "Gracz Dolny", l_mapA);
    m_secondPlayer = std::make_unique<Player>("ship2.png", "Gracz Gorny", l_mapB);
    m_grid = std::make_unique<Grid>("space.jpg");

    m_window.setFramerateLimit(60);
    mainLoop();

}

GAME::~GAME()
{

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

            m_firstPlayer->getShoot(m_secondPlayer->shoot());
            m_secondPlayer->getShoot(m_firstPlayer->shoot());

            m_firstPlayer->IsBulletsOutOfRange();
            m_secondPlayer->IsBulletsOutOfRange();
        }
        display();
    }
}

void GAME::display()
{
    m_window.draw(m_grid->getSprite());
    m_window.draw(m_secondPlayer->getSprite());
    m_window.draw(m_firstPlayer->getSprite());


    for(auto& bullet : m_firstPlayer->getVectorOfBullets())
    {
        if(bullet.isVisible())
            m_window.draw(bullet.getSprite());
    }

    for(auto& bullet : m_secondPlayer->getVectorOfBullets())
    {
        if(bullet.isVisible())
            m_window.draw(bullet.getSprite());
    }

    m_window.display();
}

void GAME::closeWindow(sf::Event& p_event)
{
    if (p_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        m_window.close();
}
