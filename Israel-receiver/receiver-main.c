/*
	To be used in https://github.com/clean-code-craft-tcq-m-2/stream-line-jessicaGL
*/

#include <stdio.h>
#include "receiver.h"

void main()
{
	SkipHeader();

	do
	{
		ReadLine();
		SplitLine();
	} while (!feof(stdin)); // Read lines until end of file is reached

	CalculateAverage();
	PrintValues();
}