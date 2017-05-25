#include<SFML/Graphics.hpp>

#ifndef IDraw_H
#define IDraw_H

class IDraw
{
public:
    virtual ~IDraw() = default;
    virtual sf::Sprite& getSprite() = 0;
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
};

#endif
