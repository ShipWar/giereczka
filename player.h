#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"idraw.h"
#include"bullet.h"
#include <chrono>


class Player : public IDraw
{
public:
    ~Player();
    Player(std::string p_adres);
    Bullet *getBullet();
    void shoot(sf::Vector2f p_direction);
private:
    Bullet* m_bullet;
};

#endif // PLAYER_H
