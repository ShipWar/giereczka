#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"idrawinterface.h"
#include"bullet.h"



class Player : public IDraw
{
public:
    ~Player();
    Player(std::string p_adres);
    sf::Sprite& getSprite() override;
    Bullet *getBullet();
private:
    Bullet* m_bullet;
};

#endif // PLAYER_H
