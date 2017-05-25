#include "idraw.h"

sf::Sprite &IDraw::getSprite()
{
    return m_Sprite;
}

void IDraw::setSprite(std::string p_adres)
{
    m_Texture.loadFromFile(p_adres);
    m_Sprite.setTexture(m_Texture);
}
