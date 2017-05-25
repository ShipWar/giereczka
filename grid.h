#ifndef GRID_H
#define GRID_H
#include<SFML/Graphics.hpp>
#include<string>
#include"idrawinterface.h"


class Grid : public IDraw
{
public:
    Grid(std::string p_adres);
    sf::Sprite& getSprite() override;
};

#endif // GRID_H
