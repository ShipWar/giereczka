#ifndef PLAYER_H
#define PLAYER_H
#include "Include/bullet.h"
#include "Include/achivement.h"

#include <memory>

class Player : public IDraw
{
    using BulletType = std::unique_ptr<Bullet>;

public:
    Player(std::string p_adres, std::string p_name, std::map<std::string, sf::Keyboard::Key> p_keyMap);
    ~Player();  
    std::vector<BulletType>& getVectorOfBullets();
    std::vector<BulletType>& shoot();
    void getShoot(std::vector<BulletType>& p_bulletsVector);
    bool isAlive() const;
    void shipControl();
    void AreBulletsOutOfRange();
    void keepShipOnTheGrid();
    int getHealth();
    int getBullets();
    void getAchivement(std::vector<std::unique_ptr<Achivement>>& p_achiveVector);


private:
    void removeBullet(std::vector<BulletType>& p_vec, BulletType &p_bullet);
    BulletType bulletFactory();

    constexpr static unsigned int HEALTH_MAX = 6;
    constexpr static unsigned int BULLETS_MAX = 20;
    constexpr static int STEP_MAX = 7;

    unsigned int m_health = 6;
    unsigned int m_bullets = 20;


    std::vector<BulletType> m_bulletsVector;
    std::string m_name;
    std::map<std::string, sf::Keyboard::Key> m_keyMap;
    sf::Vector2f m_startPosition;
    constexpr static int m_windowWidth = 1000;
    constexpr static int m_windowHeight = 700;


    int m_turn = 3;
    int m_forwardTurn = m_turn;
    int m_backwardTurn = -m_turn;
    constexpr static int m_bulletSpeed = 5;
    int m_step = 3;
    const static int m_startStep =3;

    bool guardTime();
    const std::chrono::milliseconds m_timeStampForBullets = std::chrono::milliseconds(350);   
    std::chrono::system_clock::time_point m_timePointForBullets;

    void guardTimerForSpeed_5s();
    const std::chrono::milliseconds m_timeStampForSpeed = std::chrono::seconds(5);
    std::chrono::system_clock::time_point m_timePointForSpeed;
    bool m_guardTimeChelper = true;

    sf::Music m_bulletSound;


};

#endif // PLAYER_H
