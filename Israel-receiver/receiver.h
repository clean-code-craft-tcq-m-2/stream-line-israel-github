#define VOLTAGE	0
#define CHARGE 1

void SkipHeader(void);
void ReadLine(void);
void SplitLine(void);
void ReadSensorValue(char* word, int wordNumber);
void SaveSensorValue(int value, int bufferIdx);
void SaveToBuffer(int value, int bufferIdx);
void SaveMax(int value, int bufferIdx);
void CalculateAverage();
void PrintValues();
char* GetCharacters(void);