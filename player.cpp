#include "player.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include "idraw.h"


Player::~Player()
{

}

Player::Player(std::string p_adres,
               std::string p_name,
               std::map<std::string,sf::Keyboard::Key> p_keyMap) :m_name(p_name),
                                                                  m_keyMap(p_keyMap)
{
    //createHealth();
    setVisible(true);
    setSprite(p_adres);

    if(m_name == "Gracz Dolny")
    {
        move(sf::Vector2f(m_windowWidth/2, m_windowHeight - this->getSprite().getLocalBounds().height/2));
    }
    if(m_name == "Gracz Gorny")
    {
        move(sf::Vector2f(m_windowWidth/2, this->getSprite().getLocalBounds().height/2));
        setRotation(180);
    }

    setCenterPoint();


}

std::vector<Bullet>& Player::getVectorOfBullets()
{
    return m_bulletsVector;
}

std::vector<Bullet>& Player::shoot()
{
    for(Bullet& bullet : m_bulletsVector)
    {
        if(bullet.isVisible())
        {
            if(bullet.getCurrentTime() > bullet.m_shiftTime)
            {
                bullet.moveWithSpeed(m_bulletSpeed);
                bullet.m_shiftTime = bullet.getCurrentTime() + bullet.m_ms;
            }
        }
    }

    return m_bulletsVector;
}

void Player::getShoot(std::vector<Bullet>& p_bulletsVector)
{

    for(Bullet& p_bullet : p_bulletsVector)
    {
    if(p_bullet.getSprite().getPosition().y > getPosition().y - getCenterPoint().y and
       p_bullet.getSprite().getPosition().y < getPosition().y + getCenterPoint().y and p_bullet.isVisible()  and
       p_bullet.getSprite().getPosition().x > getPosition().x - getCenterPoint().y and
       p_bullet.getSprite().getPosition().x < getPosition().x + getCenterPoint().y)
    {
        if(p_bullet.isVisible())
        {
            m_health--;
            std::cout<<m_name<<" health: \n"<<m_health<<std::endl;
            p_bullet.setVisible(false);

            p_bulletsVector.erase(
                    std::remove_if(p_bulletsVector.begin(), p_bulletsVector.end(),
                                   [](Bullet p_b){return not p_b.isVisible();}), p_bulletsVector.end());

        }
    }
  }
}

bool Player::isAlive() const
{
    if(m_health <= 0)
    {
        return false;
    }
    return true;
}

void Player::shipControl()
{
    keepShipOnTheGrid();

    if(sf::Keyboard::isKeyPressed(m_keyMap["R"]))
    {
        setRotation(getRotation()+m_turn);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["L"]))
    {
        setRotation(getRotation()-m_turn);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["U"]))
    {
        m_turn = m_forwardTurn;
        move(sin((getRotation())*3.14/180)*m_step, cos((getRotation())*3.14/180)*-m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["D"]))
    {
        m_turn = m_backwardTurn;
        move(sin((getRotation())*3.14/180)*-m_step, cos((getRotation())*3.14/180)*m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["Fire"]) and guardTimeForButtonMultiTap())
    {
        m_bullet.setPosition(getPosition());
        m_bullet.setVisible(true);
        m_bullet.setDirectory(sf::Vector2f(sin((getRotation())*3.14/180)*3, cos((getRotation())*3.14/180)*-3));
        m_bulletsVector.push_back(m_bullet);

    }
}

bool Player::guardTimeForButtonMultiTap() const
{
    auto static l_end = std::chrono::system_clock::now();
    while (std::chrono::system_clock::now() >= l_end)
    {
        l_end = std::chrono::system_clock::now() + m_timeStampForBullets;
        return true;
    }
    return false;
}

int Player::getHealth()
{
   return m_health;
}

void Player::AreBulletsOutOfRange()
{
    for(Bullet& bullet : m_bulletsVector)
    {
        if(bullet.getPosition().x < 0 or
           bullet.getPosition().x > m_windowWidth or
           bullet.getPosition().y < 0 or
           bullet.getPosition().y > m_windowHeight)
        {
             bullet.setVisible(false);

             m_bulletsVector.erase(
                            std::remove_if(m_bulletsVector.begin(), m_bulletsVector.end(),
                                          [](Bullet p_b){return not p_b.isVisible();}), m_bulletsVector.end());
        }
    }
}

void Player::keepShipOnTheGrid()
{
    if(getPosition().x < 0)
        setPosition(sf::Vector2f(getPosition().x + 10, getPosition().y));
    if(getPosition().x > m_windowWidth)
        setPosition(sf::Vector2f(getPosition().x - 10, getPosition().y));
    if(getPosition().y < 0)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y + 10));
    if(getPosition().y > m_windowHeight)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y - 10));
}
