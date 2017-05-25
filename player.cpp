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
    static std::chrono::milliseconds ms(40);
    static std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now() + ms ;

    if(m_bullet->isVisible)
    {
        if(std::chrono::system_clock::now()>end)
        {
            m_bullet->getSprite().move(p_direction);
            end = std::chrono::system_clock::now() + ms;
        }

        if(m_bullet->getSprite().getPosition().y < 0 || m_bullet->getSprite().getPosition().y > 800) //change this magic number
            m_bullet->isVisible = false;
    }
}


