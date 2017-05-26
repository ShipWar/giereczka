#include "player.h"

Player::~Player()
{
    delete m_bullet;
}

Player::Player(std::string p_adres)
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


