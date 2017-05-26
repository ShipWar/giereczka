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
    static const int windowWidth = 800;
    static const int windowHeight = 700;
    Bullet* m_bullet;
    std::chrono::milliseconds m_ms = std::chrono::milliseconds(20);
    std::chrono::time_point<std::chrono::system_clock> m_end = std::chrono::system_clock::now() + m_ms;
};

#endif // PLAYER_H
