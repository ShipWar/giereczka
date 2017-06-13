#ifndef PLAYER_H
#define PLAYER_H
#include"idraw.h"
#include"bullet.h"

class Player : public IDraw
{
public:
    ~Player();
    Player(std::string p_adres, std::string p_name, std::map<std::string, sf::Keyboard::Key> p_keyMap);
    std::vector<Bullet> &getVectorOfBullets();
    std::vector<Bullet> &shoot();
    void getShoot(std::vector<Bullet> &p_bulletsVector);
    bool isAlive() const;
    void shipControl();
    void IsBulletsOutOfRange();

private:
    bool guardTimeForButtonMultiTap() const;
    Bullet m_bullet = Bullet("bullet.png");
    std::vector<Bullet> m_bulletsVector;
    std::string m_name;
    std::map<std::string, sf::Keyboard::Key> m_keyMap;
    sf::Vector2f m_startPosition;

    constexpr static int m_windowWidth = 800;
    constexpr static int m_windowHeight = 700;

    int m_health = 20;
    int m_turn = 5;
    int m_forwardTurn = m_turn;
    int m_backwardTurn = -m_turn;

    constexpr static int m_bulletSpeed = 5;
    constexpr static int m_step = 10;
};

#endif // PLAYER_H
