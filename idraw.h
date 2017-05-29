#include<SFML/Graphics.hpp>
#include<string>
#ifndef IDraw_H
#define IDraw_H

class IDraw
{
public:
    virtual ~IDraw() = default;
    sf::Sprite& getSprite();
    void setSprite(std::string p_adres);
    bool isVisible = false;
    sf::Vector2u getTextureSize();

private:
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;

};

#endif
