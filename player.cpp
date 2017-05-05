#include "player.h"
#include <iostream>

Player::Player(sf::Sprite &p_sprite):m_sprite(p_sprite)
{
    std::cout<< "Player created\n";
}

Player::~Player()
{
    std::cout<< "Player died\n";

}

sf::Sprite& Player::getSprite()
{
    return m_sprite;
}

void Player::move(int p_width, int p_height)
{
    m_sprite.move(p_width, p_height);

}

unsigned int Player::getHealth()
{
    return m_health;
}

void Player::setHealth(unsigned int p_health)
{
    m_health = p_health;
}

unsigned int Player::getPower()
{
    return m_power;
}

void Player::setPower(unsigned int p_power)
{
    m_power = p_power;
}

unsigned int Player::getBullets()
{
    return m_bullets;
}

void Player::setBullets(unsigned int p_bullets)
{
    m_bullets = p_bullets;
}
