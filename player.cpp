#include "player.h"
#include <iostream>
Player::~Player()
{
    delete m_bullet;
}

Player::Player(std::string p_adres, std::string p_name) :m_name(p_name)
{
    this->isVisible = true;
    setSprite(p_adres);
    m_bullet = new Bullet("bullet.png");
}

Bullet* Player::getBullet()
{
    return m_bullet;
}

void Player::shoot(sf::Vector2f p_direction)
{
    if(m_bullet->isVisible)
    {
        if(std::chrono::system_clock::now()>m_end)
        {
            m_bullet->getSprite().move(p_direction);
            m_end = std::chrono::system_clock::now() + m_ms;
        }

        if(m_bullet->getSprite().getPosition().y < 0 || m_bullet->getSprite().getPosition().y > windowHeight)
            m_bullet->isVisible = false;
    }
}

void Player::getShoot(Bullet *p_bullet)
{
    sf::Vector2f l_vec(this->getSprite().getPosition().x +100, this->getSprite().getPosition().y +100);

    if(p_bullet->getSprite().getPosition().y > this->getSprite().getPosition().y && p_bullet->isVisible
        && p_bullet->getSprite().getPosition().y < l_vec.y &&
            p_bullet->getSprite().getPosition().x > this->getSprite().getPosition().x &&
            p_bullet->getSprite().getPosition().x < l_vec.x)
    {
        this->m_health--;
        std::cout<<"Health: \n"<<m_health<<std::endl;
    }
}

bool Player::isAlive()
{
    if(m_health <= 0)
    {
        std::cout<<"GAME OVER "<<m_name<<"\n";
        return false;
    }
    return true;
}

void Player::setBulletPositionBeforeShoot(Bullet* p_bullet)
{
//    p_bullet->getSprite().setPosition((this->getSprite().getPosition().x + this->getSprite().getLocalBounds().width/2),
//                                     this->getSprite().getPosition().y);
    p_bullet->getSprite().setPosition(this->getSprite().getPosition().x + 50, this->getSprite().getPosition().y);
}


