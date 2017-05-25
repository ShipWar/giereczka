#include "player.h"


Player::~Player()
{

}

Player::Player(std::string p_adres)
{
    m_Texture.loadFromFile(p_adres);
    m_Sprite.setTexture(m_Texture);

    m_bulletTexture.loadFromFile("bullet.png");
    m_bullet.setTexture(m_bulletTexture);

}

sf::Sprite& Player::getSprite()
{
    return m_Sprite;
}

sf::Sprite& Player::getBullet()
{
    return m_bullet;
}
