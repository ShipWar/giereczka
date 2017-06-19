#ifndef GAME_H
#define GAME_H
#include "idraw.h"
#include <memory>
#include "mesurments.h"
#include "achivement.h"
#include <chrono>

class Grid;
class Player;

class GAME
{    
public:
    GAME();
    ~GAME();
    void mainLoop();
private:

    void displayGame();
    void closeWindow(sf::Event &p_event);
    void createMeasurments();
    void createAchivements();

    void randomAchivements();

    void drawPlayersHealth();
    void drawPlayersBullets();
    void drawAchivements();
    void drawPlayers();
    void drawBullets();

    constexpr static std::pair<int, int> m_windowSize = std::make_pair(1000, 700);
    sf::RenderWindow m_window;
    std::unique_ptr<Grid> m_grid;
    std::unique_ptr<Player> m_firstPlayer;
    std::unique_ptr<Player> m_secondPlayer;

    sf::Music m_mainSound;

    std::vector<std::unique_ptr<Mesurments>> m_healthPictures;
    std::vector<std::unique_ptr<Mesurments>> m_bulletsPictures;
    std::vector<std::unique_ptr<Achivement>> m_Achivements;

};

#endif // GAME_H
