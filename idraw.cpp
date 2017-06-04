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

bool IDraw::isVisible()
{
    return m_visible;
}

void IDraw::setVisible(bool p_visible)
{
    m_visible = p_visible;
}

sf::Vector2f IDraw::getTextureSize()
{
    return static_cast<sf::Vector2f>(m_Texture.getSize());
}

void IDraw::move(const sf::Vector2f p_vec)
{
    m_Sprite.move(p_vec);
}

void IDraw::move(const float x, const float y)
{
    m_Sprite.move(x, y);
}

void IDraw::setRotation(const float p_angle)
{
    m_Sprite.setRotation(p_angle);
}

float IDraw::getRotation()
{
    return m_Sprite.getRotation();
}

const sf::Vector2f& IDraw::getPosition()
{
    return m_Sprite.getPosition();
}

void IDraw::setPosition(const sf::Vector2f& p_position)
{
    m_Sprite.setPosition(p_position);
}
