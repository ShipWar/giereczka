#include "bullet.h"

Bullet::Bullet(std::string p_adres)
{
    setSprite(p_adres);
    auto l_CenterPoint = sf::Vector2f(getTextureSize().x/2, getTextureSize().y/2);
    this->getSprite().setOrigin(l_CenterPoint);
}

