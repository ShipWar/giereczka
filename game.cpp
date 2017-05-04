#include "game.h"


void Game::createTextures()
{
    m_window.create(sf::VideoMode(windowWidth,windowHeight), "SHIPS WORKS");

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
    GameDisplay l_gameDisplay(m_window, m_spaceSprite, m_shipSprite);
    l_gameDisplay.setInitialPositionForObjects();

    GameLogic l_gameLogic(m_window, m_spaceSprite, m_shipSprite);

    while (m_window.isOpen())
    {

        while (m_window.pollEvent(m_event))
        {
            closeWindow();
            l_gameLogic.shipControl();

        }

        l_gameDisplay.displayGame();


    }
}

void Game::closeWindow()
{
    if (m_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        m_window.close();
}
