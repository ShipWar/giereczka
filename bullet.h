#ifndef BULLET_H
#define BULLET_H
#include "idraw.h"
#include <SFML/Graphics.hpp>

class Bullet : public IDraw
{
public:
    Bullet(std::string p_adres);
    void setDirectory(sf::Vector2f p_directory);
    sf::Vector2f getDirectory();
private:
    sf::Vector2f m_bulletDirectory;

};

#endif // BULLET_H
