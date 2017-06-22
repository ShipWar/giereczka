#include "player.h"
#include <math.h>

Player::Player(std::string p_adres,
               std::string p_name,
               std::map<std::string,sf::Keyboard::Key> p_keyMap) :m_name(p_name),
                                                                  m_keyMap(p_keyMap)
{
    setVisible(true);
    setSprite(p_adres);

    if(m_name == "Gracz Dolny")
    {
        move(sf::Vector2f(m_windowWidth/2, m_windowHeight - this->getSprite().getLocalBounds().height/2));
        m_bulletSound.openFromFile("sounds/fire1.ogg");
    }
    if(m_name == "Gracz Gorny")
    {
        move(sf::Vector2f(m_windowWidth/2, this->getSprite().getLocalBounds().height/2));
        m_bulletSound.openFromFile("sounds/fire2.ogg");
        setRotation(180);
    }

    setCenterPoint();
}

std::vector<Player::BulletType>& Player::getVectorOfBullets()
{
    return m_bulletsVector;
}

std::vector<Player::BulletType>& Player::shoot()
{
    for(BulletType& bullet : m_bulletsVector)
    {
        if(bullet->isVisible())
        {
            if(bullet->getCurrentTime() > bullet->m_shiftTime)
            {
                bullet->moveWithSpeed(m_bulletSpeed);
                bullet->m_shiftTime = bullet->getCurrentTime() + bullet->m_ms;
            }
        }
    }

    return m_bulletsVector;
}

bool Player::isAlive() const
{
    if(m_health <= 0)
    {
        return false;
    }
    return true;
}

void Player::shipControl()
{
    keepShipOnTheGrid();
    guardTimerForSpeed_5s();

    if(sf::Keyboard::isKeyPressed(m_keyMap["Fire"]) and guardTime())
    {
        if(getBullets()>0)
        {
            m_bulletSound.play();
            m_bulletsVector.push_back(bulletFactory());
        }
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["R"]))
    {
        setRotation(getRotation()+m_turn);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["L"]))
    {
        setRotation(getRotation()-m_turn);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["U"]))
    {
        m_turn = m_forwardTurn;
        move(sin((getRotation())*3.14/180)*m_step, cos((getRotation())*3.14/180)*-m_step);
    }

    if(sf::Keyboard::isKeyPressed(m_keyMap["D"]))
    {
        m_turn = m_backwardTurn;
        move(sin((getRotation())*3.14/180)*-m_step, cos((getRotation())*3.14/180)*m_step);
    }
}

bool Player::guardTime()
{
    while (std::chrono::system_clock::now() >= m_timePointForBullets)
    {
        m_timePointForBullets = std::chrono::system_clock::now() + m_timeStampForBullets;
        return true;
    }
    return false;
}

void Player::removeBullet(std::vector<Player::BulletType>& p_vec, BulletType& p_bullet)
{
    auto it = std::remove(p_vec.begin(), p_vec.end(), p_bullet) ;
    p_vec.erase(it);
}

Player::BulletType Player::bulletFactory()
{
    m_bullets--;
    BulletType l_bullet = std::make_unique<Bullet>("images/bullet.png");
    l_bullet->setPosition(getPosition());
    l_bullet->setVisible(true);
    l_bullet->setDirectory(sf::Vector2f(sin((getRotation())*3.14/180)*3, cos((getRotation())*3.14/180)*-3));
    return l_bullet;
}

int Player::getHealth()
{
    return m_health;
}

int Player::getBullets()
{
    return m_bullets;
}

void Player::getAchivement(std::vector<std::unique_ptr<Achivement>>& p_achiveVector)
{
    for(std::unique_ptr<Achivement>& p_achive : p_achiveVector)
    {
        if(p_achive->getSprite().getPosition().y > getPosition().y - getCenterPoint().y and
           p_achive->getSprite().getPosition().y < getPosition().y + getCenterPoint().y and p_achive->isVisible()  and
           p_achive->getSprite().getPosition().x > getPosition().x - getCenterPoint().y and
           p_achive->getSprite().getPosition().x < getPosition().x + getCenterPoint().y and guardTime())
        {
            if(m_bullets + std::get<0>(p_achive->getAchivements()) <= BULLETS_MAX)
                m_bullets += std::get<0>(p_achive->getAchivements());
            if(m_health + std::get<1>(p_achive->getAchivements()) <= HEALTH_MAX)
                m_health += std::get<1>(p_achive->getAchivements());
            if(m_step + std::get<2>(p_achive->getAchivements()) <= STEP_MAX)
                m_step += std::get<2>(p_achive->getAchivements());

            p_achive->setVisible(false);
            p_achive->resetTimers();
        }
    }
}

void Player::guardTimerForSpeed_5s()
{
    if(m_step > m_startStep && m_guardTimeChelper)
    {
        m_timePointForSpeed = std::chrono::system_clock::now() + m_timeStampForSpeed;
        m_guardTimeChelper = false;
    }

    while (std::chrono::system_clock::now() >= m_timePointForSpeed)
    {
        m_timePointForSpeed = std::chrono::system_clock::now() + m_timeStampForSpeed;
        m_step =m_startStep;
        m_guardTimeChelper = true;
    }
}

void Player::AreBulletsOutOfRange()
{
    for(BulletType& bullet : m_bulletsVector)
    {
        if(bullet->getPosition().x < 0 or
           bullet->getPosition().x > m_windowWidth or
           bullet->getPosition().y < 0 or
           bullet->getPosition().y > m_windowHeight)
        {
             removeBullet(m_bulletsVector, bullet);
             break; //one remove for one loop
        }
    }
}

void Player::getShoot(std::vector<BulletType>& p_bulletsVector)
{
    for(BulletType& p_bullet : p_bulletsVector)
    {
        if(p_bullet->getSprite().getPosition().y > getPosition().y - getCenterPoint().y and
           p_bullet->getSprite().getPosition().y < getPosition().y + getCenterPoint().y and p_bullet->isVisible()  and
           p_bullet->getSprite().getPosition().x > getPosition().x - getCenterPoint().y and
           p_bullet->getSprite().getPosition().x < getPosition().x + getCenterPoint().y)
        {
                m_health--;
                removeBullet(p_bulletsVector, p_bullet);
                break; //one remove for one loop
        }
  }
}

void Player::keepShipOnTheGrid()
{
    if(getPosition().x < 0)
        setPosition(sf::Vector2f(getPosition().x + 10, getPosition().y));
    if(getPosition().x > m_windowWidth)
        setPosition(sf::Vector2f(getPosition().x - 10, getPosition().y));
    if(getPosition().y < 0)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y + 10));
    if(getPosition().y > m_windowHeight)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y - 10));
}

Player::~Player()
{

}
