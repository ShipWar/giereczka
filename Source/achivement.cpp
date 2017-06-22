#include "Include/achivement.h"

Achivement::Achivement(int p_bulletBonus, int p_healthBonus, int p_speedBonus, std::string p_adres, int p_timeOne, int p_timeTwo) :
                                                               m_bulletBonus(p_bulletBonus),
                                                               m_healthBonus(p_healthBonus),
                                                               m_speedBonus(p_speedBonus)
{
    setSprite(p_adres);
    setCenterPoint();
    m_timeStampForAchivementsOne = std::chrono::seconds(p_timeOne);
    m_timeStampForAchivementsTwo = std::chrono::seconds(p_timeTwo);
    std::srand(std::time(0));
}

Achivement::~Achivement()
{

}

std::tuple<int, int, int> Achivement::getAchivements()
{
    return std::make_tuple(m_bulletBonus, m_healthBonus, m_speedBonus);

}

void Achivement::randomShow()
{
    if (std::chrono::system_clock::now() >= m_timePointForAchivementsOne)
    {
        if(not isVisible())
        {
            setPosition(sf::Vector2f(rand()% m_windowSize.first, rand()%m_windowSize.second));
            setVisible(true);
        }
        if (std::chrono::system_clock::now() >= m_timePointForAchivementsTwo)
        {
            m_timePointForAchivementsTwo = std::chrono::system_clock::now() + m_timeStampForAchivementsTwo;
            m_timePointForAchivementsOne = std::chrono::system_clock::now() + m_timeStampForAchivementsOne;
        }
    }
    else if (std::chrono::system_clock::now() <= m_timePointForAchivementsOne)
    {
        setVisible(false);
    }

}

void Achivement::resetTimers()
{
    m_timePointForAchivementsTwo = std::chrono::system_clock::now() +m_timeStampForAchivementsTwo;
    m_timePointForAchivementsOne = std::chrono::system_clock::now() +m_timeStampForAchivementsOne;

}
