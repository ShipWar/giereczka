#include "player.h"
#include <iostream>
Player::~Player()
{
    delete m_bullet;
}

Player::Player(std::string p_adres, std::string p_name, std::map<std::string, sf::Keyboard::Key> p_keyMap, sf::Vector2f p_startPosition)
                                                                                                    :m_name(p_name),
                                                                                                    m_keyMap(p_keyMap),
                                                                                                    m_startPosition(p_startPosition)
{
    this->isVisible = true;
    setSprite(p_adres);
    m_bullet = new Bullet("bullet.png");
    this->getSprite().move(m_startPosition);

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
    sf::Vector2f l_vec(this->getSprite().getPosition().x + this->getTextureSize().x,
                       this->getSprite().getPosition().y + this->getTextureSize().y);

    if(p_bullet->getSprite().getPosition().y > this->getSprite().getPosition().y &&
       p_bullet->getSprite().getPosition().y < l_vec.y &&
       p_bullet->isVisible  &&
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
    static bool l_gameOver=true;
    if(not l_gameOver)
    {
        return false;
    }
    else if(m_health <= 0)
    {
        std::cout<<"GAME OVER "<<m_name<<"\n";
        l_gameOver=false;
    }
    return true;
}

void Player::setBulletPositionBeforeShoot()
{
    this->getBullet()->getSprite().setPosition(this->getSprite().getPosition().x + getSprite().getLocalBounds().height/2 - m_bullet->getSprite().getLocalBounds().height/2,
                                               this->getSprite().getPosition().y + getTextureSize().y/2);
}

void Player::shipControl()
{
    if(sf::Keyboard::isKeyPressed(m_keyMap["R"]) &&
            this->getSprite().getPosition().x <= (m_windowWidth-this->getSprite().getLocalBounds().width-m_step))
    {
        this->getSprite().move(m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["L"]) && this->getSprite().getPosition().x>0)
    {
        this->getSprite().move(-m_step,0);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["U"]) && this->getSprite().getPosition().y>0)
    {
        this->getSprite().move(0,-m_step);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["D"]) &&
            this->getSprite().getPosition().y <= (m_windowHeight-this->getSprite().getLocalBounds().height-m_step))
    {
        this->getSprite().move(0,m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["Fire"]))
    {
        if(not this->getBullet()->isVisible)
        {
            this->setBulletPositionBeforeShoot();
            this->getBullet()->isVisible = true;
        }
    }
}
