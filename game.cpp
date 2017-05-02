#include "game.h"
#include "gamedisplay.h"

void Game::createTextures()
{
    m_window.create(sf::VideoMode(windowWidth,windowHeight), "SFML works!");

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
GameDisplay Position;
Position.InitialPosition(m_shipTexture.getSize().x, m_shipTexture.getSize().y);
m_shipSprite.setPosition(Position.shipPosition.x,Position.shipPosition.y);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                m_window.close();

            Position.getPosition(m_shipSprite.getPosition().x, m_shipSprite.getPosition().y);
            Position.changePosition(m_shipTexture.getSize().x, m_shipTexture.getSize().y);
            m_shipSprite.setPosition(Position.shipPosition.x,Position.shipPosition.y);

        }

        m_window.clear();
        m_window.draw(m_spaceSprite);
        m_window.draw(m_shipSprite);
        m_window.display();


    }
}
