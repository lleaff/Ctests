#include "stringToDouble.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAXSTRINGSIZE 1000
typedef enum { FALSE, TRUE } BOOL;

//Input processing functions
int stringToInt(char str[]);
BOOL stringIsInt(char str[]);

int randTests(int numberOfTests);
double randDouble(double lower, double upper, int resolution);

int main(int argc, char *argv[])
{
	if (argc == 1) {
		char inputString[MAXSTRINGSIZE];
		scanf("%s", inputString);
		printf("%g", stringToDouble(inputString));
	} else {
		if (argc <= 3 && !strcmp(argv[1], "--test")) {
			int testC;
			if (stringIsInt(argv[2])) {
				testC = stringToInt(argv[2]);
			} else {
				testC = 6;
			}
			srand(time(NULL));
			randTests(testC);
			return 0;
		}
	}
}

double stringToDouble(char str[])
{
}

int stringToInt(char str[])
{
	int num = 0;
	int i = (str[0] == '-') ? 1 : 0;
	for (; str[i] != '\0'; i++) {
		num = (num * 10) + (str[i] - '0');
	}
	return (str[0] == '-') ? -num : num;
}

BOOL stringIsInt(char str[])
{
	int i = (str[0] == '-') ? 1 : 0;
	for (; str[i] != '\0'; i++) {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			return FALSE;
		}
	}
	return TRUE;
}

int randInt(int lower, int upper)
{
	return (((upper - lower) * rand()) / RAND_MAX)  + lower;
}

double randDouble(double lower, double upper, int resolution)
{
	return (double)randInt(lower, upper * (pow(10, resolution))) / (pow(10, resolution));
}

int randTests(int testC)
{
}
