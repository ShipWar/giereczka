#include "player.h"
#include <iostream>
#include <math.h>

Player::~Player()
{
    delete m_bullet;
}

Player::Player(std::string p_adres, std::string p_name, std::map<std::string,
               sf::Keyboard::Key> p_keyMap) :m_name(p_name),
                                             m_keyMap(p_keyMap)
{
    m_bullet = new Bullet("bullet.png");

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

Bullet* Player::getBullet()
{
    return m_bullet;
}

void Player::shoot()
{
    if(m_bullet->isVisible())
    {
        if(std::chrono::system_clock::now()>m_end)
        {
            m_bullet->getSprite().move(m_bullet->getDirectory());
            m_end = std::chrono::system_clock::now() + m_ms;
        }

        if(m_bullet->getSprite().getPosition().x < 0 ||
           m_bullet->getSprite().getPosition().x > m_windowWidth ||
           m_bullet->getSprite().getPosition().y < 0 ||
           m_bullet->getSprite().getPosition().y > m_windowHeight)

           m_bullet->setVisible(false);
    }
}

void Player::getShoot(Bullet *p_bullet)
{
    if(p_bullet->getSprite().getPosition().y > getPosition().y - getCenterPoint().y &&
       p_bullet->getSprite().getPosition().y < getPosition().y + getCenterPoint().y &&
       p_bullet->isVisible()  &&
       p_bullet->getSprite().getPosition().x > getPosition().x - getCenterPoint().y &&
       p_bullet->getSprite().getPosition().x < getPosition().x + getCenterPoint().y)
    {
        if(p_bullet->isVisible())
        {
            m_health--;
            std::cout<<m_name<<" health: \n"<<m_health<<std::endl;
            p_bullet->setVisible(false);
        }
    }
}

bool Player::isAlive()
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

    if( getPosition().x < getCenterPoint().x ||
        getPosition().x > m_windowWidth - getCenterPoint().x ||
        getPosition().y < getCenterPoint().y ||
        getPosition().y > m_windowHeight - getCenterPoint().y)
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

    if(sf::Keyboard::isKeyPressed(m_keyMap["U"]) &&
            getPosition().x >= getCenterPoint().x &&
            getPosition().x <= m_windowWidth - getCenterPoint().x &&
            getPosition().y >= getCenterPoint().y &&
            getPosition().y <= m_windowHeight - getCenterPoint().y)
    {
        m_turn = 1;
        move(sin((getRotation())*3.14/180)*m_step, cos((getRotation())*3.14/180)*-m_step);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["D"]) &&
            getPosition().x >= getCenterPoint().x &&
            getPosition().x <= m_windowWidth - getCenterPoint().x &&
            getPosition().y >= getCenterPoint().y &&
            getPosition().y <= m_windowHeight - getCenterPoint().y)
    {
        m_turn = -1;
        move(sin((getRotation())*3.14/180)*-m_step, cos((getRotation())*3.14/180)*m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["Fire"]))
    {
        if(not getBullet()->isVisible())
        {
            m_bullet->setPosition(getPosition());
            m_bullet->setVisible(true);
            m_bullet->setDirectory(sf::Vector2f(sin((getRotation())*3.14/180)*3, cos((getRotation())*3.14/180)*-3));
        }
    }
}
