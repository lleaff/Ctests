#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

double stringToDouble(char myString[])
{
	int i;
	double num = 0;
	int fractionPart = 0;
	for (i = 0; myString[i] != '\0'; i++) {
		if (myString[i] == '.') {
			fractionPart = 1;
		} else if (myString[i] >= '0' && myString[i] <= '9') {
			if (!fractionPart) {
				num = (num * 10) + myString[i] - '0';
			} else {
				num += (myString[i] - '0') * pow(10, -fractionPart++);
			}
		}
	}
	return num;
}

char intToString(int input, char myString[])
{
}

int randInt(int lower, int upper) {
	return ((rand() * (upper - lower)) / RAND_MAX) + lower;
}

int main(int argc, char *argv[])
{
#define MAXNUMLENGTH 100
	char convertedInt[MAXNUMLENGTH];

	if (!strcmp(argv[1], "--test")) {
#define DEFAULTTESTC 6
		int testC = (argc == 3) ? (int)stringToDouble(argv[2]) : DEFAULTTESTC;
		srand(time(NULL));
		int testNum;
		int i;
		for (i = 0; i < testC; i++) {
			testNum = randInt(0, 9999);
			intToString(testNum, convertedInt);
			printf("%-6d %s\n", testNum, convertedInt);
		}
		//Test with "0"
		intToString(0, convertedInt);
		printf("%-6d %s\n", 0, convertedInt);
	} else {
		//Process arguments
		int i;
		for (i = 1; i < argc; i++) {
			intToString((int)stringToDouble(argv[i]), convertedInt);
			printf("%s\n", convertedInt);
		}
	}
}
