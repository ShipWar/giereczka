#include "game.h"
#include "grid.h"
#include "player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

GAME::GAME()
{
    m_window.create(sf::VideoMode(m_windowSize.first, m_windowSize.second), "SHIPS WARSS");

    sf::Vector2i l_windowPosition(150, 50);

    m_window.setPosition(l_windowPosition);


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

    m_firstPlayer = std::make_unique<Player>("images/DurrrSpaceShip.png", "Gracz Dolny", l_mapA);
    m_secondPlayer = std::make_unique<Player>("images/ship2.png", "Gracz Gorny", l_mapB);
    m_grid = std::make_unique<Grid>("images/space.jpg");

    m_window.setFramerateLimit(60); // max Frames Per Secound set to 60FPS

    createMeasurments();
    createAchivements();

    m_mainSound.openFromFile("sounds/main.ogg");
    m_mainSound.setVolume(30);
    m_mainSound.setLoop(true);
    m_mainSound.play();


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
            randomAchivements();
            m_firstPlayer->shipControl();
            m_secondPlayer->shipControl();

            m_firstPlayer->getShoot(m_secondPlayer->shoot());
            m_secondPlayer->getShoot(m_firstPlayer->shoot());

            m_firstPlayer->AreBulletsOutOfRange();
            m_secondPlayer->AreBulletsOutOfRange();

            m_firstPlayer->getAchivement(m_Achivements);
            m_secondPlayer->getAchivement(m_Achivements);
        }
        displayGame();
    }
}

void GAME::displayGame()
{
    m_window.draw(m_grid->getSprite());

    drawPlayersHealth();
    drawPlayersBullets();
    drawAchivements();
    drawPlayers();
    drawBullets();

    m_window.display();
}

void GAME::closeWindow(sf::Event& p_event)
{
    if (p_event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        m_window.close();
}

void GAME::drawPlayersHealth()
{
    m_healthPictures.at(m_secondPlayer->getHealth())->getSprite().setPosition(sf::Vector2f(0,0));

    m_window.draw(m_healthPictures.at(m_secondPlayer->getHealth())->getSprite());

    m_healthPictures.at(m_firstPlayer->getHealth())->getSprite().setPosition(
            sf::Vector2f(0, m_windowSize.second - m_healthPictures[0]->getSprite().getTexture()->getSize().y));

    m_window.draw(m_healthPictures.at(m_firstPlayer->getHealth())->getSprite());

}

void GAME::drawPlayersBullets()
{
    m_bulletsPictures.at(m_secondPlayer->getBullets()/2)->getSprite().setPosition(sf::Vector2f(0,
                                                m_healthPictures[0]->getSprite().getTexture()->getSize().y));

    m_window.draw(m_bulletsPictures.at(m_secondPlayer->getBullets()/2)->getSprite());

    m_bulletsPictures.at(m_firstPlayer->getBullets()/2)->getSprite().setPosition(
            sf::Vector2f(0, m_windowSize.second - m_bulletsPictures[0]->getSprite().getTexture()->getSize().y
                - m_healthPictures[0]->getSprite().getTexture()->getSize().y));

    m_window.draw(m_bulletsPictures.at(m_firstPlayer->getBullets()/2)->getSprite());
}

void GAME::drawAchivements()
{
    for(auto& v : m_Achivements)
    {
        if(v->isVisible())
        m_window.draw(v->getSprite());
    }
}

void GAME::drawPlayers()
{
    m_window.draw(m_secondPlayer->getSprite());
    m_window.draw(m_firstPlayer->getSprite());
}

void GAME::drawBullets()
{
    for(auto& bullet : m_firstPlayer->getVectorOfBullets())
    {
        if(bullet->isVisible())
            m_window.draw(bullet->getSprite());
    }

    for(auto& bullet : m_secondPlayer->getVectorOfBullets())
    {
        if(bullet->isVisible())
            m_window.draw(bullet->getSprite());
    }
}

void GAME::createMeasurments()
{
    m_healthPictures.push_back(std::make_unique<Mesurments>("images/health/0.png"));
    m_healthPictures.push_back(std::make_unique<Mesurments>("images/health/1.png"));
    m_healthPictures.push_back(std::make_unique<Mesurments>("images/health/2.png"));
    m_healthPictures.push_back(std::make_unique<Mesurments>("images/health/3.png"));
    m_healthPictures.push_back(std::make_unique<Mesurments>("images/health/4.png"));
    m_healthPictures.push_back(std::make_unique<Mesurments>("images/health/5.png"));
    m_healthPictures.push_back(std::make_unique<Mesurments>("images/health/6.png"));

    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/0.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/1.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/2.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/3.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/4.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/5.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/6.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/7.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/8.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/9.png"));
    m_bulletsPictures.push_back(std::make_unique<Mesurments>("images/bullets/10.png"));
}

void GAME::createAchivements()
{
    m_Achivements.push_back(std::make_unique<Achivement>(2, 0, 0, "images/bonus/BulletIcon.png", 3, 6));
    m_Achivements.push_back(std::make_unique<Achivement>(0, 2, 0, "images/bonus/shield.png", 7, 10));
    m_Achivements.push_back(std::make_unique<Achivement>(0, 0, 2, "images/bonus/Bolt.png", 10, 14));
}

void GAME::randomAchivements()
{
    for(std::unique_ptr<Achivement>& achi : m_Achivements)
    {
        achi->randomShow();
    }
}









