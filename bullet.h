#ifndef BULLET_H
#define BULLET_H
#include "idraw.h"
#include <SFML/Graphics.hpp>
#include <chrono>

class Bullet : public IDraw
{
public:
    Bullet();
    using timePoint = std::chrono::time_point<std::chrono::system_clock>;
    using milisecound = std::chrono::milliseconds;
    using microseconds = std::chrono::microseconds;
    milisecound m_ms = milisecound(2);
    milisecound m_guardTime = milisecound(200);
    microseconds m_mics = microseconds(2);
    timePoint m_shiftTime ;

    timePoint getCurrentTime() const;

    Bullet(std::string p_adres);
    void setDirectory(sf::Vector2f p_directory);
    sf::Vector2f getDirectory();
    void move() override;
private:
    sf::Vector2f m_bulletDirectory;

};

#endif // BULLET_H
