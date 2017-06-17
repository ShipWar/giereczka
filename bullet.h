#ifndef BULLET_H
#define BULLET_H
#include "idraw.h"
#include <chrono>

class Bullet : public IDraw
{
    using timePoint = std::chrono::time_point<std::chrono::system_clock>;
    using milisecound = std::chrono::milliseconds;
    using microseconds = std::chrono::microseconds;

public:
    Bullet();
    Bullet(std::string p_adres, int p_counter = 0);
    ~Bullet();

    milisecound m_ms = milisecound(10);
    milisecound m_guardTime = milisecound(200);   //add geters and seters
    timePoint m_shiftTime ;
    timePoint getCurrentTime() const;

    void setDirectory(sf::Vector2f p_directory);
    sf::Vector2f getDirectory();
    void moveWithSpeed(int p_speed);

private:
    sf::Vector2f m_bulletDirectory;
    int m_counter;
};

#endif // BULLET_H
