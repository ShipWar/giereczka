#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"idraw.h"
#include"bullet.h"
#include <chrono>
#include <string>
#include <vector>
#include <map>


class Player : public IDraw
{
public:
    ~Player();
    Player(std::string p_adres, std::string p_name, std::map<std::string, sf::Keyboard::Key> p_keyMap);
    Bullet *getBullet();
    void shoot();
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
    std::chrono::time_point<std::chrono::system_clock> m_end ;

    std::string m_name;
    std::map<std::string, sf::Keyboard::Key> m_keyMap;
    sf::Vector2f m_startPosition;
    int m_step = 1;

    sf::Vector2f m_CenterPoint;

    sf::Vector2f m_bulletDirectory;

};

#endif // PLAYER_H
