#include "player.h"
#include <iostream>
Player::~Player()
{
    delete m_bullet;
}

Player::Player(std::string p_adres, std::string p_name, std::vector<sf::Keyboard::Key> p_keyVector, sf::Vector2f p_startPosition)
                                                                                                    :m_name(p_name),
                                                                                                    m_keyVector(p_keyVector),
                                                                                                    m_startPosition(p_startPosition)
{
    this->isVisible = true;
    setSprite(p_adres);
    m_bullet = new Bullet("bullet.png");
    this->getSprite().move(m_startPosition);
    createHealth();

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

        if(m_bullet->getSprite().getPosition().y < 0 || m_bullet->getSprite().getPosition().y > m_windowHeight)
            m_bullet->isVisible = false;
    }
}

void Player::getShoot(Bullet *p_bullet)
{
    sf::Vector2f l_vec(this->getSprite().getPosition().x +100, this->getSprite().getPosition().y +50);

    if(p_bullet->getSprite().getPosition().y > this->getSprite().getPosition().y && p_bullet->isVisible
        && p_bullet->getSprite().getPosition().y < l_vec.y &&
            p_bullet->getSprite().getPosition().x > this->getSprite().getPosition().x &&
            p_bullet->getSprite().getPosition().x < l_vec.x)
    {
        if(p_bullet->isVisible)
        {
            this->m_health--;
            std::cout<<m_name<<" health: \n"<<m_health<<std::endl;
            p_bullet->isVisible = false;
        }
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

void Player::setBulletPositionBeforeShoot()
{
    this->getBullet()->getSprite().setPosition(this->getSprite().getPosition().x + this->getSprite().getLocalBounds().width/3,
                                      this->getSprite().getPosition().y);
}

void Player::shipControl()
{
    if(sf::Keyboard::isKeyPressed(m_keyVector[0]) &&
            this->getSprite().getPosition().x<=(m_windowWidth-this->getSprite().getLocalBounds().width-m_step))
    {
        this->getSprite().move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(m_keyVector[1]) && this->getSprite().getPosition().x>0)
    {
        this->getSprite().move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(m_keyVector[2]) && this->getSprite().getPosition().y>0)
    {
        this->getSprite().move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(m_keyVector[3]) &&
            this->getSprite().getPosition().y<=(m_windowHeight-this->getSprite().getLocalBounds().height-m_step))
    {
        this->getSprite().move(0,m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyVector[4]))
    {
        if(not this->getBullet()->isVisible)
        {
            this->setBulletPositionBeforeShoot();
            this->getBullet()->isVisible = true;
        }
    }
}

void Player::createHealth()
{

}


