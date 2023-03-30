#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "sender.h"

int chargePercentReadings[50] = {0,1,1,2,8,12,12,15,17,18,18,19,21,21,22,23,29,33,34,36,36,39,39,40,40,41,42,50,50,51,52,60,60,62,65,65,67,71,74,79,82,86,87,90,93,97,98,99,100,100};
int temperatureInCReadings[50] = {0,1,3,4,5,5,5,6,7,7,8,12,12,13,14,15,16,16,21,21,23,23,24,24,24,26,26,28,29,29,30,30,30,33,34,35,36,36,37,37,37,38,39,41,43,44,46,48,49,49};

char line[20];

void SendReadingsInCSV(void)
{
	int i;

	for (i = 0; i < 50; i++)
	{
		FormatLine(i, chargePercentReadings[i], temperatureInCReadings[i]);
		printf("%s\n", line);
	}
}

void FormatLine(int index, int chargePercent, int temperatureInC)
{
	sprintf(line,"%d,%d,%d", index, chargePercent, temperatureInC);
}

int main(void)
{
	char header[40] = "Index,Charge,Temperature";
	printf("%s\n", header);
	SendReadingsInCSV();

	FormatLine(1, 10, 15);
	assert(strcmp(line, "1,10,15") == 0);
	assert(strcmp(line, "7,8,3") != 0);

	return 0;
}

