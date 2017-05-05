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
    void closeWindow();
private:
    static const int windowWidth = 800;
    static const int windowHeight = 700;

    sf::RenderWindow m_window;

    sf::Texture m_spaceTexture;
    sf::Sprite m_spaceSprite;
    sf::Texture m_shipTexture;
    sf::Sprite m_shipSprite;
    sf::Texture m_shipTextureTwo;
    sf::Sprite m_shipSpriteTwo;


    sf::Event m_event;

};

#endif // GAME_H
