#ifndef GAME_H
#define GAME_H

#include "Include/idraw.h"

#include <functional>


class Grid;
class Player;
class Achivement;
class Mesurments;

class GAME
{    
public:
    GAME();
    ~GAME();
    void createGame();
    void Run();

private:
    void displayGame();
    void closeWindow(sf::Event &p_event);

    void createMeasurments();
    void createAchivements();

    void randomAchivements();

    void drawPlayersHealth();
    void drawPlayersBullets();



    void drawContainer(std::initializer_list<sf::Sprite> p_list);

    template<typename T1, typename T2>
    void drawContainer(const T1 &p_container, T2& p_window,
                       std::function<void(const T1&, T2&) > p_func = [](const T1& p_container, T2& p_window)
    {
        for(auto& element : p_container)
        {
            if(element->isVisible())
               p_window.draw(element->getSprite());
        }

        }
    );

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
