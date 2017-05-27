#ifndef GAME_H
#define GAME_H
#include<SFML/Graphics.hpp>
#include "idraw.h"
class Grid;
class Player;

class GAME
{    
public:
    GAME();
    ~GAME();
    void mainLoop();
    void display();
    void closeWindow(sf::Event &p_event);

private:
    static const int windowWidth = 800;
    static const int windowHeight = 700;
    sf::RenderWindow m_window;
    Grid *m_grid;
    Player *m_firstPlayer;
    Player *m_secondPlayer;

    std::vector<IDraw*> m_vectorOfDrawableElemnts;


};

#endif // GAME_H
