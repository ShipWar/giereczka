#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include"idrawinterface.h"

class Player : public IDraw
{
public:
    ~Player();
    Player(std::string p_adres);
    sf::Sprite& getSprite() override;
    sf::Sprite& getBullet();
private:
    sf::Texture m_bulletTexture;
    sf::Sprite m_bullet;
};

#endif // PLAYER_H
