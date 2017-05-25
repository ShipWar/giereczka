#include "grid.h"


Grid::Grid(std::string p_adres)
{
    m_Texture.loadFromFile(p_adres);
    m_Sprite.setTexture(m_Texture);
}

sf::Sprite& Grid::getSprite()
{
    return m_Sprite;
}
