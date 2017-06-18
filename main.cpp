#include "game.h"
#include <iostream>
#include <SFML/Audio.hpp>
int main()
{
    try
    {
        GAME game;
        game.mainLoop();
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

}
