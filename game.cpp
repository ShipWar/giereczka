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

<<<<<<< HEAD
    GameLogic l_gameLogic(m_window, m_spaceSprite, m_shipSprite);
=======
l_gameLogic.InitialPosition(m_window, m_shipTexture);
m_shipSprite.setPosition(l_gameLogic.shipPosition);
>>>>>>> 42ad3b5a7f3477d3e7179ce446a59c3c2d8df176

    while (m_window.isOpen())
    {

<<<<<<< HEAD
        while (m_window.pollEvent(m_event))
        {
            closeWindow();
            l_gameLogic.shipControl();

        }

        l_gameDisplay.displayGame();


=======
            l_gameLogic.shipControl(event, m_window, m_shipTexture, m_shipSprite);
            m_shipSprite.setPosition(l_gameLogic.shipPosition);
        }

        l_gameDisplay.displayGame(m_window, m_spaceSprite, m_shipSprite);
>>>>>>> 42ad3b5a7f3477d3e7179ce446a59c3c2d8df176
    }
}

void Game::closeWindow()
{
    if (m_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        m_window.close();
}
