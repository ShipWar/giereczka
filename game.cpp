#include "game.h"

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
GameDisplay l_gameDisplay;
GameLogic l_gameLogic;

l_gameLogic.InitialPosition(m_window, m_shipTexture);
m_shipSprite.setPosition(l_gameLogic.shipPosition);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                m_window.close();

            l_gameLogic.shipControl(event, m_window, m_shipTexture, m_shipSprite);
            m_shipSprite.setPosition(l_gameLogic.shipPosition);
        }

        l_gameDisplay.displayGame(m_window, m_spaceSprite, m_shipSprite);
    }
}
