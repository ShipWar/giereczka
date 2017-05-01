#include "game.h"

void Game::createTextures()
{
    m_window.create(sf::VideoMode(800, 700), "SFML works!");

    m_spaceTexture.loadFromFile("space.jpg");

    m_spaceSprite.setTexture(m_spaceTexture);

    m_shipTexture.loadFromFile("DurrrSpaceShip.png");

    m_shipSprite.setTexture(m_shipTexture);

}

void Game::startGame()
{
    createTextures();
    mainLoop();
}

void Game::mainLoop()
{

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                m_window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                m_shipSprite.move(20,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                m_shipSprite.move(-20,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                m_shipSprite.move(0,-20);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                m_shipSprite.move(0,20);
            }

        }

        m_window.clear();
        m_window.draw(m_spaceSprite);
        m_window.draw(m_shipSprite);
        m_window.display();
    }
}
