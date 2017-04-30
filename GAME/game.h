#ifndef GAME_H
#define GAME_H
#include<SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void createTextures();
    void startGame();
private:
    sf::RenderWindow m_window;
    sf::Texture m_spaceTexture;
    sf::Sprite m_spaceSprite;
};

#endif // GAME_H
