#ifndef BULLET_H
#define BULLET_H
#include "idraw.h"
#include <SFML/Graphics.hpp>

class Bullet : public IDraw
{
public:
    Bullet(std::string p_adres);
};

#endif // BULLET_H
