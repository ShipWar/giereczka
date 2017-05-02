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
    static const int windowWidth = 800;
    static const int windowHeight = 700;

private:
    sf::RenderWindow m_window;
    sf::Texture m_spaceTexture;
    sf::Sprite m_spaceSprite;
    sf::Texture m_shipTexture;
    sf::Sprite m_shipSprite;

};

#endif // GAME_H
