#ifndef SENDERINPUTHANDLER_H
#define SENDERINPUTHANDLER_H
#include <sstream>
#include <vector>

typedef enum measureType{
    Index,
    charge,
    temperature
}measureType;

class senderInputHandler{

public:
senderInputHandler(){}
~senderInputHandler(){}

std::vector<std::string> scanDataFromPipe();
std::vector<std::string> splitString(std::string completeString);
std::vector<int> saveBatteryParameters(std::vector<std::string> scannedMeasurenmets, measureType measurenmentType);
};




#endif