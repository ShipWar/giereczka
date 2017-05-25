#ifndef GRID_H
#define GRID_H
#include<SFML/Graphics.hpp>
#include<string>
#include"idraw.h"


class Grid : public IDraw
{
public:
    Grid(std::string p_adres);
};

#endif // GRID_H
