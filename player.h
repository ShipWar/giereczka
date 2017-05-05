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

private:
    sf::Sprite& m_sprite;
    unsigned int m_health;
    unsigned int m_power;
    unsigned int m_bullets;
};

#endif // PLAYER_H
