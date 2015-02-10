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

int intToString(int input, char myString[])
{
	int i = 0;
	if (input < 0) {
		myString[i] = '-';
		return 1 + intToString(-input, &myString[1]);
	}
	if (input / 10 > 0) {
		i = intToString(input / 10, myString);
	}
	myString[i] = input % 10 + '0';
	i++;
	myString[i] = '\0';
	return i;
}

int randInt(int lower, int upper) {
	return ((rand() * (upper - lower)) / RAND_MAX) + lower;
}

#define MAXNUMLENGTH 100

int getIntFromInput(int *isEOF)
{
	char userInput[MAXNUMLENGTH];
	if (fgets(userInput, MAXNUMLENGTH, stdin) != NULL && 
			!(!strcmp(userInput, "q\n") || !strcmp(userInput, "quit\n") || !strcmp(userInput, "exit\n"))) {
		userInput[strlen(userInput) - 1] = 
			userInput[strlen(userInput) - 1] == '\n' ? '\0' : userInput[strlen(userInput) - 1];
		return (int)stringToDouble(userInput);
	} else {
		*isEOF = 1;
		return 0;
	}
}

int main(int argc, char *argv[])
{
	char convertedInt[MAXNUMLENGTH];

	if (argc > 1) {
		if (!strcmp(argv[1], "--test")) {
			int testResult = 0;
#define DEFAULTTESTC 6
			int testC = (argc == 3) ? (int)stringToDouble(argv[2]) : DEFAULTTESTC;
			srand(time(NULL));
			int testNum;
			int i;
			for (i = 0; i < testC; i++) {
				testNum = randInt(0, 9999);
				intToString(testNum, convertedInt);
				printf("%-6d %s\n", testNum, convertedInt);
				if ((int)stringToDouble(convertedInt) != testNum) {
					testResult++;
				}
			}
			//Test with "0"
			intToString(0, convertedInt);
			printf("%-6d %s\n", 0, convertedInt);
			printf("\nTest result: %s", testResult ? "FAILURE" : "SUCCESS");
			if (testResult) {
				printf(" %d errors", testResult);
			}
			printf("\n");
			return testResult;
		} else { //Process arguments
			int i;
			for (i = 1; i < argc; i++) {
				intToString((int)stringToDouble(argv[i]), convertedInt);
				printf("%s\n", convertedInt);
			}
		}
	} else { //No arguments, take input from stdin
		int isEOF = 0;
		while (1) {
			intToString(getIntFromInput(&isEOF), convertedInt);
			if (isEOF) {
				break;
			}
			printf("%s\n", convertedInt);
			convertedInt[0] = '\0';
		}
	}
	return 0;
}
