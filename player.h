#ifndef PLAYER_H
#define PLAYER_H
#include "bullet.h"
#include <memory>


class Player : public IDraw
{
    using BulletType = std::unique_ptr<Bullet>;

public:
    Player(std::string p_adres, std::string p_name, std::map<std::string, sf::Keyboard::Key> p_keyMap);
    ~Player();  
    std::vector<BulletType> &getVectorOfBullets();
    std::vector<BulletType> &shoot();
    void getShoot(std::vector<BulletType> &p_bulletsVector);
    bool isAlive() const;
    void shipControl();
    void AreBulletsOutOfRange();
    void keepShipOnTheGrid();
    int getHealth();

private:
    bool guardTimeForButtonMultiTap();
    void removeBullet(std::vector<BulletType>& p_vec, BulletType &p_bullet);
    BulletType bulletFactory();
    std::vector<BulletType> m_bulletsVector;
    std::string m_name;
    std::map<std::string, sf::Keyboard::Key> m_keyMap;
    sf::Vector2f m_startPosition;
    constexpr static int m_windowWidth = 1000;
    constexpr static int m_windowHeight = 700;
    unsigned int m_health = 9;
    int m_turn = 3;
    int m_forwardTurn = m_turn;
    int m_backwardTurn = -m_turn;
    constexpr static int m_bulletSpeed = 5;
    constexpr static int m_step = 3;

    const std::chrono::milliseconds m_timeStampForBullets = std::chrono::milliseconds(350);   
    std::chrono::system_clock::time_point m_timePointForBullets;



};

#endif // PLAYER_H
