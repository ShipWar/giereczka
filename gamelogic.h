#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <SFML/Graphics.hpp>

class GameLogic
{
public:
    void InitialPosition(sf::RenderWindow& p_window, sf::Texture p_texture);
    void shipControl(sf::Event p_event, sf::RenderWindow& p_window, sf::Texture p_texture, sf::Sprite p_ship);
    sf::Vector2f shipPosition;

};

#endif // GAMELOGIC_H
