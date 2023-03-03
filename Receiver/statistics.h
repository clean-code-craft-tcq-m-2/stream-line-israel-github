#ifndef STATISTICS_H
#define STATISTICS_H
#include <vector>

class Statistics{
    private:
    std::vector<int> m_Measurenmentslist;

    public:
    Statistics(){}
    Statistics(std::vector<int> measurenments){ m_Measurenmentslist = measurenments;}
    ~Statistics(){}

    void setMeasurenmentList(std::vector<int> list);
    int calculateMinimumValue();
    int calculateMaximumValue();
    std::vector<float> calculateSimpleMovingAvrg(float periodSize);
};
#endif