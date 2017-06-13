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
    ~Player();
    Player(std::string p_adres, std::string p_name, std::map<std::string, sf::Keyboard::Key> p_keyMap);
    std::vector<Bullet> &getBullet();
    std::vector<Bullet> &shoot();
    void getShoot(std::vector<Bullet> &p_bulletsVector);
    bool isAlive() const;
    void shipControl();

    bool guardTime();

private:
    unsigned int m_health = 10;
    static const int m_windowWidth = 800;
    static const int m_windowHeight = 700;

    Bullet m_bullet = Bullet("bullet.png");
    std::vector<Bullet> m_bulletsVector;



    std::string m_name;
    std::map<std::string, sf::Keyboard::Key> m_keyMap;
    sf::Vector2f m_startPosition;

    int m_step = 1;
    int m_turn = 1;
};

#endif // PLAYER_H
