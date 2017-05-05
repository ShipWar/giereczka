#include "gamedisplay.h"
#include <iostream>

GameDisplay::GameDisplay(sf::RenderWindow &p_window, sf::Sprite &p_background, sf::Sprite &p_ship, sf::Sprite& p_shipTwo):
                                                                                                   m_window(p_window),
                                                                                                   m_background(p_background),
                                                                                                   m_ship(p_ship),
                                                                                                   m_shipTwo(p_shipTwo)
{

}

void GameDisplay::displayGame()
{
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_ship);
    m_window.draw(m_shipTwo);
    m_window.display();
}

void GameDisplay::setInitialPositionForObjects()
{
    m_ship.move((m_window.getSize().x)/2 -m_ship.getLocalBounds().width/2, m_window.getSize().y - m_ship.getLocalBounds().height);
    m_shipTwo.move((m_window.getSize().x)/2 -m_shipTwo.getLocalBounds().width/2, 0);
}
