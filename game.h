#ifndef GAME_H
#define GAME_H
#include "idraw.h"
#include <memory>

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
    constexpr static std::pair<int, int> m_windowSize = std::make_pair(800, 700);
    sf::RenderWindow m_window;
    std::unique_ptr<Grid> m_grid;
    std::unique_ptr<Player> m_firstPlayer;
    std::unique_ptr<Player> m_secondPlayer;





};

#endif // GAME_H
