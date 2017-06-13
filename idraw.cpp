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

bool IDraw::isVisible() const
{
    return m_visible;
}

void IDraw::setVisible(bool p_visible)
{
    m_visible = p_visible;
}

sf::Vector2f IDraw::getTextureSize() const
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

void IDraw::move()
{
    //empty
}

void IDraw::setRotation(const float p_angle)
{
    m_Sprite.setRotation(p_angle);
}

float IDraw::getRotation() const
{
    return m_Sprite.getRotation();
}

const sf::Vector2f& IDraw::getPosition() const
{
    return m_Sprite.getPosition();
}

void IDraw::setPosition(const sf::Vector2f& p_position)
{
    m_Sprite.setPosition(p_position);
}

void IDraw::setOrigin(const sf::Vector2f& p_origin)
{
    m_Sprite.setOrigin(p_origin);
}

void IDraw::setCenterPoint()
{
    auto l_vec = sf::Vector2f(getTextureSize().x/2, getTextureSize().y/2);
    m_centerPoint = l_vec;
    setOrigin(l_vec);
}

const sf::Vector2f& IDraw::getCenterPoint() const
{
    return m_centerPoint;
}
