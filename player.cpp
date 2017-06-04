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



    this->isVisible = true;
    setSprite(p_adres);

    if(m_name == "Gracz Dolny")
    {
        m_startPosition = sf::Vector2f(m_windowWidth/2, m_windowHeight-this->getSprite().getLocalBounds().height/2);
    }
    if(m_name == "Gracz Gorny")
    {
        m_startPosition = sf::Vector2f(m_windowWidth/2, this->getSprite().getLocalBounds().height/2);
        this->getSprite().setRotation(180);
    }

    m_bullet = new Bullet("bullet.png");
    this->getSprite().move(m_startPosition);
    m_CenterPoint = sf::Vector2f(getTextureSize().x/2, getTextureSize().y/2);
    this->getSprite().setOrigin(m_CenterPoint);
}

Bullet* Player::getBullet()
{
    return m_bullet;
}

void Player::shoot()
{
    if(m_bullet->isVisible)
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

            m_bullet->isVisible = false;
    }
}

void Player::getShoot(Bullet *p_bullet)
{
    if(p_bullet->getSprite().getPosition().y > this->getSprite().getPosition().y - m_CenterPoint.y &&
       p_bullet->getSprite().getPosition().y < this->getSprite().getPosition().y + m_CenterPoint.y &&
       p_bullet->isVisible  &&
       p_bullet->getSprite().getPosition().x > this->getSprite().getPosition().x - m_CenterPoint.y &&
       p_bullet->getSprite().getPosition().x < this->getSprite().getPosition().x + m_CenterPoint.y)
    {
        if(p_bullet->isVisible)
        {
            this->m_health--;
            std::cout<<m_name<<" health: \n"<<m_health<<std::endl;
            p_bullet->isVisible = false;
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

void Player::setBulletPositionBeforeShoot()
{
    this->getBullet()->getSprite().setPosition(this->getSprite().getPosition().x,
                                               this->getSprite().getPosition().y);
}

void Player::shipControl()
{

    if(this->getSprite().getPosition().x < m_CenterPoint.x ||
            this->getSprite().getPosition().x > m_windowWidth - m_CenterPoint.x ||
            this->getSprite().getPosition().y < m_CenterPoint.y ||
            this->getSprite().getPosition().y > m_windowHeight - m_CenterPoint.y)
    {
        this->getSprite().move(sin((this->getSprite().getRotation())*3.14/180)*-20*m_step, cos((this->getSprite().getRotation())*3.14/180)*20*m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["R"]))
    {
        this->getSprite().setRotation(this->getSprite().getRotation()+m_turn);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["L"]))
    {
        this->getSprite().setRotation(this->getSprite().getRotation()-m_turn);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["U"]) &&
            this->getSprite().getPosition().x >= m_CenterPoint.x &&
            this->getSprite().getPosition().x <= m_windowWidth - m_CenterPoint.x &&
            this->getSprite().getPosition().y >= m_CenterPoint.y &&
            this->getSprite().getPosition().y <= m_windowHeight - m_CenterPoint.y)
    {
        m_turn = 1;
        this->getSprite().move(sin((this->getSprite().getRotation())*3.14/180)*m_step, cos((this->getSprite().getRotation())*3.14/180)*-m_step);
    }
    if(sf::Keyboard::isKeyPressed(m_keyMap["D"]) &&
            this->getSprite().getPosition().x >= m_CenterPoint.x &&
            this->getSprite().getPosition().x <= m_windowWidth - m_CenterPoint.x &&
            this->getSprite().getPosition().y >= m_CenterPoint.y &&
            this->getSprite().getPosition().y <= m_windowHeight - m_CenterPoint.y)
    {
        m_turn = -1;
        this->getSprite().move(sin((this->getSprite().getRotation())*3.14/180)*-m_step, cos((this->getSprite().getRotation())*3.14/180)*m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["Fire"]))
    {
        if(not this->getBullet()->isVisible)
        {
            this->setBulletPositionBeforeShoot();
            this->getBullet()->isVisible = true;
            m_bullet->setDirectory(sf::Vector2f(sin((this->getSprite().getRotation())*3.14/180)*3, cos((this->getSprite().getRotation())*3.14/180)*-3));
        }
    }
}
