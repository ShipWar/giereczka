#include "game.h"

Game::Game()
{

}

void Game::createTextures()
{
    m_window.create(sf::VideoMode(800, 800), "SFML works!");

    m_spaceTexture.loadFromFile("space.jpg");

    m_spaceSprite.setTexture(m_spaceTexture);

}

void Game::startGame()
{
    createTextures();
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear();
        m_window.draw(m_spaceSprite);
        m_window.display();
    }
}
