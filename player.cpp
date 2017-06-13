#include "player.h"
#include <iostream>
#include <math.h>
#include <algorithm>

Player::~Player()
{
    //delete m_bullet;
}

Player::Player(std::string p_adres, std::string p_name, std::map<std::string,
               sf::Keyboard::Key> p_keyMap) :m_name(p_name),
                                             m_keyMap(p_keyMap)
{
    setVisible(true);
    setSprite(p_adres);

    if(m_name == "Gracz Dolny")
    {
        move(sf::Vector2f(m_windowWidth/2, m_windowHeight-this->getSprite().getLocalBounds().height/2));
    }
    if(m_name == "Gracz Gorny")
    {
        move(sf::Vector2f(m_windowWidth/2, this->getSprite().getLocalBounds().height/2));
        setRotation(180);
    }


    setCenterPoint(sf::Vector2f(getTextureSize().x/2, getTextureSize().y/2));

}

std::vector<Bullet>& Player::getBullet()
{
    return m_bulletsVector;
}


std::vector<Bullet>& Player::shoot()
{
    std::cout<<m_bulletsVector.size()<<std::endl;
    int i=0;

    for(Bullet& v : m_bulletsVector)
    {
        std::cout<<"bullet:"<<i<<" size: "<<m_bulletsVector.size()<<std::endl;
        i++;
        if(v.isVisible())
        {
            if(v.getCurrentTime() > v.m_shiftTime)
            {
                v.move();
                v.m_shiftTime = v.getCurrentTime() + v.m_ms;

            }

            if(v.getPosition().x < 0 or
               v.getPosition().x > m_windowWidth or
               v.getPosition().y < 0 or
               v.getPosition().y > m_windowHeight)
            {
                 v.setVisible(false);
                 m_bulletsVector.erase(m_bulletsVector.begin()+i);
            }
        }

    }
    return m_bulletsVector;
}

void Player::getShoot(std::vector<Bullet>& p_bulletsVector)
{
    int i=0;
    for(Bullet& p_bullet : p_bulletsVector)
    {
    if(p_bullet.getSprite().getPosition().y > getPosition().y - getCenterPoint().y and
       p_bullet.getSprite().getPosition().y < getPosition().y + getCenterPoint().y and p_bullet.isVisible()  and
       p_bullet.getSprite().getPosition().x > getPosition().x - getCenterPoint().y and
       p_bullet.getSprite().getPosition().x < getPosition().x + getCenterPoint().y)
    {
        if(p_bullet.isVisible())
        {
            m_health--;
            std::cout<<m_name<<" health: \n"<<m_health<<std::endl;
            p_bullet.setVisible(false);
            p_bulletsVector.erase(p_bulletsVector.begin()+i);

        }
    }
  }
}

bool Player::isAlive() const
{
    static bool l_gameOver=true;
    if(not l_gameOver)
    {
        return false;
    }
    else if(m_health <= 0)
    {
        std::cout<<"GAME OVER "<<m_name<<"\n";
        l_gameOver=false;
    }
    return true;
}

void Player::shipControl()
{

    if(getPosition().x < getCenterPoint().x or getPosition().x > m_windowWidth - getCenterPoint().x or
       getPosition().y < getCenterPoint().y or getPosition().y > m_windowHeight - getCenterPoint().y)
    {
        move(sin((getRotation())*3.14/180)*-20*m_step, cos((getRotation())*3.14/180)*20*m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["R"]))
    {
        setRotation(getRotation()+m_turn);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["L"]))
    {
        setRotation(getRotation()-m_turn);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["U"]) and getPosition().x >= getCenterPoint().x and
       getPosition().x <= m_windowWidth - getCenterPoint().x &&  getPosition().y >= getCenterPoint().y and
       getPosition().y <= m_windowHeight - getCenterPoint().y)
    {
        m_turn = 1;
        move(sin((getRotation())*3.14/180)*m_step, cos((getRotation())*3.14/180)*-m_step);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["D"]) and getPosition().x >= getCenterPoint().x and
       getPosition().x <= m_windowWidth - getCenterPoint().x && getPosition().y >= getCenterPoint().y and
       getPosition().y <= m_windowHeight - getCenterPoint().y)
    {
        m_turn = -1;
        move(sin((getRotation())*3.14/180)*-m_step, cos((getRotation())*3.14/180)*m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["Fire"]) and guardTime())
    {            
        m_bullet.setPosition(getPosition());
        m_bullet.setVisible(true);
        m_bullet.setDirectory(sf::Vector2f(sin((getRotation())*3.14/180)*3, cos((getRotation())*3.14/180)*-3));
        m_bulletsVector.push_back(m_bullet);

    }
}

bool Player::guardTime()
{
    static auto l_end = std::chrono::system_clock::now() - std::chrono::milliseconds(10) ;
    while (std::chrono::system_clock::now() >= l_end)
    {
        l_end = std::chrono::system_clock::now() + std::chrono::milliseconds(500);
        return true;
    }
    return false;
}


