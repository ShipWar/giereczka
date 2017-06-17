#include "player.h"
#include <math.h>
#include <algorithm>
#include "idraw.h"

Player::Player(std::string p_adres,
               std::string p_name,
               std::map<std::string,sf::Keyboard::Key> p_keyMap) :m_name(p_name),
                                                                  m_keyMap(p_keyMap)
{
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

std::vector<Player::BulletType> &Player::getVectorOfBullets()
{
    return m_bulletsVector;
}

std::vector<Player::BulletType> &Player::shoot()
{
    for(BulletType& bullet : m_bulletsVector)
    {
        if(bullet->isVisible())
        {
            if(bullet->getCurrentTime() > bullet->m_shiftTime)
            {
                bullet->moveWithSpeed(m_bulletSpeed);
                bullet->m_shiftTime = bullet->getCurrentTime() + bullet->m_ms;
            }
        }
    }

    return m_bulletsVector;
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
        m_bulletsVector.push_back(bulletFactory());
    }
}

bool Player::guardTimeForButtonMultiTap()
{
    while (std::chrono::system_clock::now() >= m_timePointForBullets)
    {
        m_timePointForBullets = std::chrono::system_clock::now() + m_timeStampForBullets;
        return true;
    }
    return false;
}

void Player::removeBullet(std::vector<Player::BulletType> &p_vec, BulletType& p_bullet)
{
      p_vec.erase(std::remove(p_vec.begin(), p_vec.end(), p_bullet), p_vec.end());
}

Player::BulletType Player::bulletFactory()
{
    static int l_counter =0;
    l_counter++;
    BulletType l_bullet = std::make_unique<Bullet>("images/bullet.png", l_counter);
    l_bullet->setPosition(getPosition());
    l_bullet->setVisible(true);
    l_bullet->setDirectory(sf::Vector2f(sin((getRotation())*3.14/180)*3, cos((getRotation())*3.14/180)*-3));
    return l_bullet;
}

int Player::getHealth()
{
   return m_health;
}

void Player::AreBulletsOutOfRange()
{
    for(BulletType& bullet : m_bulletsVector)
    {
        if(bullet->getPosition().x < 0 or
           bullet->getPosition().x > m_windowWidth or
           bullet->getPosition().y < 0 or
           bullet->getPosition().y > m_windowHeight)
        {
             removeBullet(m_bulletsVector, bullet);
             break; //one remove for one loop
        }
    }
}

void Player::getShoot(std::vector<BulletType>& p_bulletsVector)
{
    for(BulletType& p_bullet : p_bulletsVector)
    {
    if(p_bullet->getSprite().getPosition().y > getPosition().y - getCenterPoint().y and
       p_bullet->getSprite().getPosition().y < getPosition().y + getCenterPoint().y and p_bullet->isVisible()  and
       p_bullet->getSprite().getPosition().x > getPosition().x - getCenterPoint().y and
       p_bullet->getSprite().getPosition().x < getPosition().x + getCenterPoint().y)
    {
            m_health--;
            removeBullet(p_bulletsVector, p_bullet);
            break; //one remove for one loop
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

Player::~Player()
{

}
