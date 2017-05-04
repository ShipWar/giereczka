#include "game.h"
#include <exception>
#include <iostream>

int main()
{
    try
    {
    Game l_game;
    l_game.startGame();
    }
    catch(std::exception& e)
    {
        std::cout<<e.what();
    }

    return 0;
}
