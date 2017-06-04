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
    bool isVisible();
    void setVisible(bool p_visible);
    sf::Vector2f getTextureSize();
    void move(const sf::Vector2f p_vec);
    void move(const float x, const float y);
    void setRotation(const float p_angle);
    float getRotation();
    const sf::Vector2f &getPosition();
    void setPosition(const sf::Vector2f &p_position);

private:
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
    bool m_visible = false;

};

#endif
