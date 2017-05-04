#ifndef GAME_H
#define GAME_H
#include<SFML/Graphics.hpp>
#include "gamedisplay.h"
#include "gamelogic.h"

class Game
{
public:
    void createTextures();
    void startGame();
    void mainLoop();
<<<<<<< HEAD
    void closeWindow();
private:
    static const int windowWidth = 800;
    static const int windowHeight = 700;
=======
    const int windowWidth = 800;
    const int windowHeight = 700;

private:
>>>>>>> 42ad3b5a7f3477d3e7179ce446a59c3c2d8df176
    sf::RenderWindow m_window;
    sf::Texture m_spaceTexture;
    sf::Sprite m_spaceSprite;
    sf::Texture m_shipTexture;
    sf::Sprite m_shipSprite;
    sf::Event m_event;

};

#endif // GAME_H
