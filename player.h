#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"idraw.h"
#include"bullet.h"



class Player : public IDraw
{
public:
    ~Player();
    Player(std::string p_adres);
    Bullet *getBullet();
private:
    Bullet* m_bullet;
};

#endif // PLAYER_H
