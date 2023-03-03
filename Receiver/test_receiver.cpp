#include "test_receiver.h"
#include <assert.h>
#include <iostream>

using namespace std;

std::vector<std::string>  inputTest = { "1, 2, 99", "2,4,99", "3,6,99", "4,8,98", "5,10,99", "6,12,67", "7,14,70", "8,16,80", "9, 18, 60", "10, 20, 90"};

void test_getMeasurenmentsData()
{
    cout <<"[test_getMeasurenmentsData]--------------TEST STARTED--------------\n";
    cout <<"[test_getMeasurenmentsData]-----saving charge measurenments\n";
    senderInputHandler inputhandler;

    vector<int> expectedOutput = {2,4,6,8,10,12,14,16,18,20};
    vector<int> actualOutput   = inputhandler.saveBatteryParameters(inputTest, measureType::charge);
    assert(expectedOutput == actualOutput);

    cout <<"[test_getMeasurenmentsData]-----saving temperature measurenments\n";
    expectedOutput = {99,99,99,98,99,67,70,80,60,90};
    actualOutput   = inputhandler.saveBatteryParameters(inputTest, measureType::temperature);
    assert(expectedOutput == actualOutput);

    cout <<"[test_getMeasurenmentsData]--------------TEST OK--------------\n";
}

void test_statistics()
{
    cout <<"[test_statistics]--------------TEST STARTED--------------\n";
    cout <<"[test_statistics]-----calculate min charge value\n";
    vector<int> chargemeasurenmentsList = {5,10,15,20,30,50,60,80,100};
    senderInputHandler inputhandler;
    Statistics statisticsHandler;
    statisticsHandler.setMeasurenmentList(chargemeasurenmentsList);

    int expectedOutput = 5;
    int actualOutput   = statisticsHandler.calculateMinimumValue();
    assert(expectedOutput == actualOutput);

    cout <<"[test_statistics]-----calculate max charge value\n";
    expectedOutput = 100;
    actualOutput   = statisticsHandler.calculateMaximumValue();
    assert(expectedOutput == actualOutput);

    cout <<"[test_statistics]-----calculate simple moving average charge values\n";
    int periodSizeTest = 5;

    std::vector<float> expectedOutput1 = {16,25,35,48,64};
    std::vector<float> actualOutput1   = statisticsHandler.calculateSimpleMovingAvrg(periodSizeTest);
    assert(expectedOutput1 == actualOutput1);

    cout <<"[test_statistics]--------------TEST OK--------------\n";
}

void runTests()
{
    test_getMeasurenmentsData();
    test_statistics();
}