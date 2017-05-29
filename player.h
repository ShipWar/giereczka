#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"idraw.h"
#include"bullet.h"
#include <chrono>
#include <string>
#include <vector>
#include <unordered_map>


class Player : public IDraw
{
public:
    ~Player();
    Player(std::string p_adres, std::string p_name, std::vector<sf::Keyboard::Key> p_keyVector, sf::Vector2f p_startPosition);
    Bullet *getBullet();
    void shoot(sf::Vector2f p_direction);
    void getShoot(Bullet *p_bullet);
    bool isAlive();
    void setBulletPositionBeforeShoot();
    void shipControl();
private:
    unsigned int m_health = 10;
    static const int m_windowWidth = 800;
    static const int m_windowHeight = 700;
    Bullet* m_bullet;
    std::chrono::milliseconds m_ms = std::chrono::milliseconds(2);
    std::chrono::time_point<std::chrono::system_clock> m_end = std::chrono::system_clock::now() + m_ms;
    std::string m_name;
    std::vector<sf::Keyboard::Key> m_keyVector;
    sf::Vector2f m_startPosition;
    int m_step = 1;
};

#endif // PLAYER_H
