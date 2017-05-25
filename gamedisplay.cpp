#include "gamedisplay.h"
#include <iostream>

GameDisplay::GameDisplay(sf::RenderWindow &p_window, sf::Sprite &p_background, sf::Sprite &p_firstShip, sf::Sprite& p_secoundShip, sf::Sprite p_bulllet):
                                                                                                   m_window(p_window),
                                                                                                   m_background(p_background),
                                                                                                   m_firstShip(p_firstShip),
                                                                                                   m_secoundShip(p_secoundShip),
                                                                                                   m_bullet(p_bulllet)
{
    setInitialPositionForObjects();
}

GameDisplay::~GameDisplay()
{
    std::cout<<"Finish of displaying\n";

}

void GameDisplay::displayGame()
{
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_firstShip);
    m_window.draw(m_secoundShip);
    m_window.draw(m_bullet);
    m_window.display();
}

void GameDisplay::setInitialPositionForObjects()
{
    m_firstShip.move((m_window.getSize().x)/2 -m_firstShip.getLocalBounds().width/2,
                     m_window.getSize().y - m_firstShip.getLocalBounds().height);
    m_secoundShip.move((m_window.getSize().x)/2 -m_secoundShip.getLocalBounds().width/2, 0);
}
