#include "player.h"
#include <iostream>

Player::Player(sf::Sprite &p_sprite):m_sprite(p_sprite)
{
    std::cout<< "Player created"<<std::endl;
}

Player::~Player()
{
    std::cout<< "Player died"<<std::endl;
}

sf::Sprite& Player::getSprite()
{
    return m_sprite;
}

void Player::move(int p_width, int p_height)
{
    m_sprite.move(p_width, p_height);

}
