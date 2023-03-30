#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receiver.h"

char* line = NULL; // Buffer to store line
size_t lineSize; // Max chars to read from line
size_t readChars; // Number of read characters
int lineCounter = 0; //
int maxValues[2];
float avgValues[2];
int sensorBuffers[2][5];

char* GetCharacters(void)
{
	/*char* line = malloc(50); // Allocate memory
	char* linep = line;
	int maxLen = 50;
	int len = maxLen;

	if (line == NULL) // Failed to allocate memory
	{
		return NULL;
	}*/

	int c;

	for (;;)
	{
		c = fgetc(stdin); // Get character from console

		if (c == EOF)
		{
			break;
		}
		else
		{
			printf("%c", c);
		}
	}
}

void ReadLine(void)
{
	lineCounter++;
	readChars = getline(&line, &lineSize, stdin);
}

void ReadSensorValue(char* word, int wordNumber)
{
	int value;

	if ((wordNumber == 3) || (wordNumber == 6))
	{
		value = atoi(word); // string to int
		SaveSensorValue(value, (wordNumber / 3) - 1);
	}
}

void SplitLine(void)
{
	char* word;
	int wordNumber = 1; // 3 & 6

	word = strtok(line, " ");

	while (word != NULL)
	{
		word = strtok(NULL, " ");
		wordNumber++;
		ReadSensorValue(word, wordNumber);
	}
}

void SkipHeader(void)
{
	do
	{
		ReadLine();
	} while (lineCounter < 2);
}

void SaveSensorValue(int value, int bufferIdx)
{
	SaveToBuffer(value, bufferIdx);
	SaveMax(value, bufferIdx);
}

void SaveMax(int value, int bufferIdx)
{
	if (value > maxValues[bufferIdx])
	{
		maxValues[bufferIdx] = value;
	}
}

void SaveToBuffer(int value, int bufferIdx)
{
	static int voltageIdx = 0;
	static int chargeIdx = 0;

	if (bufferIdx == VOLTAGE)
	{
		sensorBuffers[bufferIdx][voltageIdx % 5] = value;
		voltageIdx++;
	}
	else //CHARGE
	{
		sensorBuffers[bufferIdx][chargeIdx % 5] = value;
		chargeIdx++;
	}
}

void CalculateAverage()
{
	int i = 0;
	float avgVoltage = 0.0F;
	float avgCharge = 0.0F;

	for (i = 0; i < 5; i++)
	{
		avgValues[VOLTAGE] += sensorBuffers[VOLTAGE][i];
		avgValues[CHARGE] += sensorBuffers[CHARGE][i];
	}

	avgValues[VOLTAGE] /= 5.0F;
	avgValues[CHARGE] /= 5.0F;
}

void PrintValues()
{
	printf("Max Voltage: %d , Max Charge: %d\n", maxValues[VOLTAGE], maxValues[CHARGE]);
	printf("Average voltage of last 5 values: %.2f\n", avgValues[VOLTAGE]);
	printf("Average charge of last 5 values: %.2f\n", avgValues[CHARGE]);
}