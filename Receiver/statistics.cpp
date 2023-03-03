#include "statistics.h"
#include "algorithm"

void Statistics::setMeasurenmentList(std::vector<int> list)
{
    m_Measurenmentslist = list;
}

int Statistics::calculateMinimumValue()
{
    std::vector<int> l_sortedMeasurenmentsList = m_Measurenmentslist;
    std::sort(l_sortedMeasurenmentsList.begin(), l_sortedMeasurenmentsList.end());
    return l_sortedMeasurenmentsList.front();
}
int Statistics::calculateMaximumValue()
{
    std::vector<int> l_sortedMeasurenmentsList = m_Measurenmentslist;
    std::sort(l_sortedMeasurenmentsList.begin(), l_sortedMeasurenmentsList.end());
    return l_sortedMeasurenmentsList.back();
}

std::vector<float> Statistics::calculateSimpleMovingAvrg(float periodSize)
{
    std::vector<float> simpleMovingAvrgs;
    float simpleMovingsum = 0;
    int sampleSize = m_Measurenmentslist.size();

    for(int i=periodSize-1; i<sampleSize; i++)
    {
        simpleMovingsum = m_Measurenmentslist.at(i)+ m_Measurenmentslist.at(i-1) +
                          m_Measurenmentslist.at(i-2)+m_Measurenmentslist.at(i-3)+
                          m_Measurenmentslist.at(i-4);
        simpleMovingAvrgs.push_back(simpleMovingsum/periodSize);
    }
    return simpleMovingAvrgs;
}