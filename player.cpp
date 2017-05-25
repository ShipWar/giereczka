#include "player.h"


Player::~Player()
{
    delete m_bullet;
}

Player::Player(std::string p_adres)
{
    m_Texture.loadFromFile(p_adres);
    m_Sprite.setTexture(m_Texture);

    m_bullet = new Bullet("bullet.png");

}

sf::Sprite& Player::getSprite()
{
    return m_Sprite;
}

Bullet* Player::getBullet()
{
    return m_bullet;
}
