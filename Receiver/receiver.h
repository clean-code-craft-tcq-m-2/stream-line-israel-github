#ifndef RECEIVER_H
#define RECEIVER_H
#include "senderInputHandler.h"
#include "statistics.h"
#include "map"

static std::vector<int> temperatureMeasurenments;
static std::vector<int> chargeMeasurenments;

static std::map<measureType, std::string> headerStrings = {{measureType::charge, "Charge Statistics"}, 
                                                    {measureType::temperature, "Temperature Statistics"}};
static Statistics statisticsHandler;

std::string formatOutput(std::vector<int> measurenments, measureType type);
void getReadingsData();


#endif