#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"idraw.h"
#include"bullet.h"
#include <chrono>
#include <string>
#include <map>


class Player : public IDraw
{
public:

    using timePoint = std::chrono::time_point<std::chrono::system_clock>;
    using milisecound = std::chrono::milliseconds;

    ~Player();
    Player(std::string p_adres, std::string p_name, std::map<std::string, sf::Keyboard::Key> p_keyMap);
    Bullet *getBullet() const;
    void shoot();
    void getShoot(Bullet *p_bullet);
    bool isAlive() const;
    void shipControl();
    timePoint getCurrentTime() const;

private:
    unsigned int m_health = 10;
    static const int m_windowWidth = 800;
    static const int m_windowHeight = 700;
    Bullet* m_bullet;

    milisecound m_ms = milisecound(2);
    timePoint m_shiftTime ;

    std::string m_name;
    std::map<std::string, sf::Keyboard::Key> m_keyMap;
    sf::Vector2f m_startPosition;

    int m_step = 1;
    int m_turn = 1;
};

#endif // PLAYER_H
