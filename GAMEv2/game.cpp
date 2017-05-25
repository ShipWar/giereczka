#include "game.h"

GAME::GAME()
{
    m_window.create(sf::VideoMode(windowWidth,windowHeight, 16), "SHIPS WARSS");

    m_spaceTexture.loadFromFile("space.jpg");
    m_spaceSprite.setTexture(m_spaceTexture);

    m_shipTexture.loadFromFile("DurrrSpaceShip.png");
    m_shipSprite.setTexture(m_shipTexture);

    m_shipTextureTwo.loadFromFile("spikedShip.png");
    m_shipSpriteTwo.setTexture(m_shipTextureTwo);

    m_bulletTexture.loadFromFile("bullet.png");
    m_bullet.setTexture(m_bulletTexture);
}

void GAME::mainLoop()
{
    while (m_window.isOpen())
    {
        sf::Event l_event;
        while (m_window.pollEvent(l_event))
        {
            if (l_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                m_window.close();


        }

        m_window.draw(m_spaceSprite);
        m_window.display();
    }
}
