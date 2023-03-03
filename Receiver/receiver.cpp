#include <iostream>
#include "receiver.h"

 std::vector<std::string>  mock_input = { "1, 2, 99", "2,4,99", "3,6,99", "4,8,98", "5,10,99", "6,12,67", "7,14,70", "8,16,80", "9, 18, 60", "10, 20, 90",
                                        "11, 27, 71", "12,41,34", "13,68,30", "14,81,92", "15,15,59", "16,72,60", "17,99,57", "18,18,81", "19, 15, 39", "20, 20, 41",
                                        "21, 28, 77", "22,42,98", "23,60,30", "24,82,29", "25,1,58", "26,22,61", "27,19,27", "28,16,18", "29, 51, 32", "30, 20, 11",
                                        "31, 21, 75", "32,44,58", "33,61,44", "34,83,12", "35,19,57", "36,28,61", "37,4,71", "38,61,22", "39, 53, 31", "40, 20, 14",
                                        "41, 22, 66", "42,41,45", "43,16,7", "44,8,2", "45,11,56", "46,12,69", "47,14,79", "48,60,3", "49, 18, 3", "50, 20, 88" };

std::string formatOutput(std::vector<int> measurenments, measureType type)
{
    const int PERIODSIZE = 5;
    std::string outputString;
    statisticsHandler.setMeasurenmentList(measurenments);
 std::string maxValueString = "Max Value: " + std::to_string(statisticsHandler.calculateMaximumValue());
    std::string minValueString = "Min Value: " + std::to_string(statisticsHandler.calculateMinimumValue());
    std::string simpleMovingAvrgString = "Simple Moving Average: ";
    std::vector<float> simpleMovingAvrgList = statisticsHandler.calculateSimpleMovingAvrg(PERIODSIZE);
    for(float singleSMA: simpleMovingAvrgList)
    {
        simpleMovingAvrgString = simpleMovingAvrgString + std::to_string(singleSMA) + " ";
    }
    std::string headerString = headerStrings.at(type);
    outputString = headerString + "\n" + maxValueString + "\n" + minValueString + "\n" + simpleMovingAvrgString + "\n";
    return outputString;
}

void getReadingsData()
{
    senderInputHandler inputHandler;
    //std::vector<std::string> inputmeasurenment = inputHandler.scanDataFromPipe();
    chargeMeasurenments      = inputHandler.saveBatteryParameters(mock_input, measureType::charge);
    temperatureMeasurenments = inputHandler.saveBatteryParameters(mock_input, measureType::temperature);
}

int main()
{
    getReadingsData();
    std::string chargeOutputString = formatOutput(chargeMeasurenments, measureType::charge);
    std::string temperatureOutputString = formatOutput(temperatureMeasurenments, measureType::temperature);

    std::cout << chargeOutputString;
    std::cout << temperatureOutputString;

    return 0;
}