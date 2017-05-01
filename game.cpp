#include "game.h"

constexpr int windowSizeX = 800;                                    //Szerokość okna
constexpr int windowSizeY = 700;                                    //Wysokość okna

sf::Vector2u shipSize;                                              //Stworzenie wektora przechowującego wymiary statku

void Game::createTextures()
{
    m_window.create(sf::VideoMode(windowSizeX,windowSizeY), "SFML works!");

    m_spaceTexture.loadFromFile("space.jpg");

    m_spaceSprite.setTexture(m_spaceTexture);

    m_shipTexture.loadFromFile("DurrrSpaceShip.png");
shipSize = m_shipTexture.getSize();                                 //Pobranie wymiaru statku
    m_shipSprite.setTexture(m_shipTexture);

}

void Game::startGame()
{
    createTextures();
    mainLoop();
}

void Game::mainLoop()
{
    m_shipSprite.setPosition((windowSizeX-shipSize.x)/2,windowSizeY-shipSize.y);         //Wyśrodkowanie statku na dole okna
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
