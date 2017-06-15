#ifndef GAME_H
#define GAME_H
#include "idraw.h"
#include <memory>
#include "mesurments.h"

class Grid;
class Player;

class GAME
{    
public:
    GAME();
    ~GAME();
private:
    void mainLoop();
    void display();
    void closeWindow(sf::Event &p_event);

    constexpr static std::pair<int, int> m_windowSize = std::make_pair(1000, 700);
    sf::RenderWindow m_window;
    std::unique_ptr<Grid> m_grid;
    std::unique_ptr<Player> m_firstPlayer;
    std::unique_ptr<Player> m_secondPlayer;

    void createMeasurments();

    std::vector<Mesurments> m_healthPictures;

};

#endif // GAME_H
