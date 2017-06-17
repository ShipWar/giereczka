#include "bullet.h"
#include <iostream>

Bullet::Bullet()
{

}

Bullet::timePoint Bullet::getCurrentTime() const
{
    return std::chrono::system_clock::now();
}

Bullet::Bullet(std::string p_adres, int p_counter) : m_counter(p_counter)
{
    std::cout<<"Bullet Construtor "<<m_counter<<std::endl;
    setSprite(p_adres);
    setCenterPoint();
}

Bullet::~Bullet()
{
    std::cout<<"Bullet Destructor "<<m_counter<<std::endl;

}

void Bullet::setDirectory(sf::Vector2f p_directory)
{
    m_bulletDirectory = p_directory;
}

sf::Vector2f Bullet::getDirectory()
{
    return m_bulletDirectory;
}

void Bullet::moveWithSpeed(int p_speed)
{
    IDraw::move(getDirectory().x * p_speed, getDirectory().y * p_speed);
}


