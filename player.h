#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


class Player
{
public:
    Player(sf::Sprite& p_sprite);
    ~Player();
    sf::Sprite &getSprite();

    void move(int p_width, int p_height);
    unsigned int getHealth();
    void setHealth(unsigned int p_health);
    unsigned int getPower();
    void setPower(unsigned int p_power);
    unsigned int getBullets();
    void setBullets(unsigned int p_bullets);

private:
    sf::Sprite& m_sprite;
    unsigned int m_health;
    unsigned int m_power;
    unsigned int m_bullets;
};

#endif // PLAYER_H
