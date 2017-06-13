#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::timePoint Bullet::getCurrentTime() const
{
    return std::chrono::system_clock::now();
}

Bullet::Bullet(std::string p_adres)
{
    setSprite(p_adres);
    setCenterPoint(sf::Vector2f(getTextureSize().x/2, getTextureSize().y/2));
}

void Bullet::setDirectory(sf::Vector2f p_directory)
{
    m_bulletDirectory = p_directory;
}

sf::Vector2f Bullet::getDirectory()
{
    return m_bulletDirectory;
}

void Bullet::move()
{
    IDraw::move(getDirectory());
}


