#include "Include/game.h"
#include <iostream>
#include <SFML/Audio.hpp>
int main()
{
    try
    {
        GAME ShipsWars;

        ShipsWars.createGame();

        ShipsWars.Run();
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

}
