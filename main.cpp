#include "game.h"
#include <exception>
#include <iostream>
#include <chrono>

int main()
{

    auto l_start = std::chrono::steady_clock::now();

    try
    {
        Game l_game;
        l_game.startGame();
    }
    catch(std::exception& e)
    {
        std::cout<<e.what();
    }

    auto l_end = std::chrono::steady_clock::now();

    std::chrono::duration<double> l_time = std::chrono::duration_cast<std::chrono::seconds>(l_end-l_start);

    std::cout<<"Game lasted: "<< l_time.count()<<"s\n";

    return 0;
}
