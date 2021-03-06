#ifndef IDraw_H
#define IDraw_H
#include <chrono>
#include <memory>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class IDraw
{
public:
    virtual ~IDraw() {};
    sf::Sprite& getSprite();
    void setSprite(std::string p_adres);
    bool isVisible() const;
    void setVisible(bool p_visible);
    sf::Vector2f getTextureSize() const;
    virtual void move(const sf::Vector2f p_vec);
    virtual void move(const float x, const float y);
    virtual void move();
    void setRotation(const float p_angle);
    float getRotation() const;
    const sf::Vector2f& getPosition() const;
    void setPosition(const sf::Vector2f &p_position);
    void setOrigin(const sf::Vector2f &p_origin);
    void setCenterPoint();
    const sf::Vector2f& getCenterPoint() const;
    void setTexture(std::string p_adres);

private:
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
    bool m_visible = false;
    sf::Vector2f m_centerPoint;

};

#endif
