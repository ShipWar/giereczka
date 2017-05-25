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
