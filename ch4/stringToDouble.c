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
		double num = stringToDouble(inputString);
		printf("%g", num);
	} else {
		if (argc <= 3 && !strcmp(argv[1], "--test")) {
			int testC;
			if (argc == 3 && stringIsInt(argv[2])) {
				testC = stringToInt(argv[2]);
			} else {
				testC = 6;
			}
			srand(time(NULL));
			return randTests(testC);
		} else {
			int i;
			double num;
			for (i = 1; i < argc; i++) {
				num = stringToDouble(argv[i]);
				printf("%g%s", num, (i < argc - 1 ? "\n" : ""));
			}
			return 0;
		}
	}
}

BOOL charIsDigit(char myChar)
{
	return (myChar >= '0' && myChar <= '9');
}

int charToInt(char myChar)
{
	return (myChar - '0');
}

double stringToDouble(char str[])
{
	double num = 0;
	int i = str[0] == '-' || str[0] == '+' ? 1 : 0;
	BOOL significand = TRUE; //inverse being exponent
	int point = strlen(str), base = 0;
	int exponent = 0;
	BOOL negExponent = FALSE;
	for (; str[i] != '\0'; i++) {
		if(significand) {
			if (str[i] == '.') {
				point = i;
			} else if (str[i] == 'e' || str[i] == 'E') {
				significand = FALSE;
				base = i;
			} else if (charIsDigit(str[i])) {
				num = (i < point) ? (num * 10 + charToInt(str[i])) : (num + (charToInt(str[i]) * pow(10, -(i - point))));
			} else {
				goto errorParse;
			}
		} else {
			if (i == base + 1 && (str[i] == '-' || str[i] == '+')) {
				negExponent = str[i] == '-' ? TRUE : FALSE;
			} else if (charIsDigit(str[i])) {
				exponent = exponent * 10 + charToInt(str[i]);
			} else {
				goto errorParse;
			}
		}
	}
	if (0) { //Just wanted to try
errorParse: fprintf(stderr, "ERROR: Can't parse string (\"%s\")", str);
	return NAN;
	}
	if (base != 0) {
		exponent = negExponent ? -exponent : exponent;
		num = num * pow(10, exponent);
	}
	return (str[0] == '-') ? -num : num;;
}

int stringToInt(char str[])
{
	int num = 0;
	int i = (str[0] == '-') ? 1 : 0;
	for (; str[i] != '\0'; i++) {
		num = (num * 10) + charToInt(str[i]);
	}
	return (str[0] == '-') ? -num : num;
}

BOOL stringIsInt(char str[])
{
	int i = (str[0] == '-') ? 1 : 0;
	for (; str[i] != '\0'; i++) {
		if (!charIsDigit(str[i])) {
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

//Note: Automated equality tests don't mean much and fail seemingly randomly
int randTests(int testC)
{
	int correctness = 0;
	double testDouble, convertedDouble;
	char testString[MAXSTRINGSIZE];
	for (; testC > 0; testC--) {
		testDouble = randDouble(-1000, 1000, 3);
		printf("%g", testDouble);
		sprintf(testString, "%g", testDouble);
		convertedDouble = stringToDouble(testString);
		correctness += (convertedDouble == testDouble);
		if (convertedDouble != testDouble) {
			printf("\tFAIL  %g", convertedDouble);
		}
		printf("\n");
	}
	return correctness;
}
