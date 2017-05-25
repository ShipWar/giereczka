#include "bullet.h"

Bullet::Bullet(std::string p_adres)
{
    m_Texture.loadFromFile(p_adres);
    m_Sprite.setTexture(m_Texture);
}

sf::Sprite &Bullet::getSprite()
{
    return m_Sprite;
}
