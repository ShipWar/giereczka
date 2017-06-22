#ifndef ACHIVEMENT_H
#define ACHIVEMENT_H

#include "Include/idraw.h"

#include <chrono>
#include <tuple>

class Achivement : public IDraw
{
public:
    Achivement(int p_bulletBonus, int p_healthBonus, int p_speedBonus, std::string p_adres, int p_timeOne, int p_timeTwo);
    ~Achivement();
    std::tuple<int, int, int> getAchivements();

    void randomShow();
    void resetTimers();
private:
    unsigned int m_bulletBonus;
    unsigned int m_healthBonus;
    unsigned int m_speedBonus;
    constexpr static std::pair<int, int> m_windowSize = std::make_pair(1000, 700);
    std::chrono::milliseconds m_timeStampForAchivementsOne = std::chrono::seconds(2);
    std::chrono::milliseconds m_timeStampForAchivementsTwo = std::chrono::seconds(5);
    std::chrono::system_clock::time_point m_timePointForAchivementsOne;
    std::chrono::system_clock::time_point m_timePointForAchivementsTwo;
};

#endif // ACHIVEMENT_H
