#include "senderInputHandler.h"

std::vector<std::string> senderInputHandler::scanDataFromPipe()
{
    std::vector<std::string> scannedMeasurenmets;
    char readMeasurenment[30];
    int endOfScans;
    bool isHeader = true;

    while((endOfScans = scanf("%30s",readMeasurenment)) == 1)
    {
        if(!isHeader)
        {
            scannedMeasurenmets.push_back(readMeasurenment);
        }
        isHeader = false;
    }
    return scannedMeasurenmets;
}

std::vector<std::string> senderInputHandler::splitString(std::string completeString)
{
    std::stringstream sscompleteString(completeString);
    std::vector<std::string> splitReadings;
     while(sscompleteString.good()) {
      std::string substr;
      std::getline(sscompleteString, substr, ',');
      splitReadings.push_back(substr);
   }
   return splitReadings;
}

std::vector<int> senderInputHandler::saveBatteryParameters(std::vector<std::string> scannedMeasurenmets, measureType measurenmentType)
{
   std::vector<int> savedMeasurenments;

   for(uint8_t measureIndex=0; measureIndex<scannedMeasurenmets.size(); measureIndex++)
    {
        std::vector<std::string> measurenmentSet = splitString(scannedMeasurenmets.at(measureIndex));
        savedMeasurenments.push_back(stoi(measurenmentSet.at(measurenmentType)));
    }

    return savedMeasurenments;
}
