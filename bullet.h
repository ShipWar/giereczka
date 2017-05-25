#ifndef BULLET_H
#define BULLET_H
#include "idrawinterface.h"
#include <SFML/Graphics.hpp>

class Bullet : public IDraw
{
public:
    Bullet(std::string p_adres);
    sf::Sprite& getSprite() override;
};

#endif // BULLET_H
