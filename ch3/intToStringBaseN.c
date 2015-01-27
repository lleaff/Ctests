#include "intToStringBaseN.h"
#include "binarySearch.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSTRINGSIZE 1000

typedef enum { FALSE, TRUE } BOOL;

int stringToInt(char myString[])
{
	const int base = 10;
	int i;
	int num = 0;
	for(i = 0; myString[i] != '\0'; i++) {
		num = (num * base) + (myString[i] - '0');
	}
	return num;
}

int main(int argc, char **argv)
{
	char output[MAXSTRINGSIZE];
	int inputNum;
	int inputBase;
	BOOL test = FALSE;
	if (argc == 1) {
		scanf("%d", &inputNum), scanf("%d", &inputBase);
		intToStringBaseN(inputNum, inputBase, output);
		printf("%s", output);

	} else if (argc == 2 && !strcmp(argv[1], "--test")) {
		test = TRUE;
	} else {
		int i;
		for (i = 1; i < argc; i++) {
			intToStringBaseN(stringToInt(argv[i]), stringToInt(argv[i + 1]), output);
			i++;
			printf("%s", output);
			if (i < argc - 1) {
				printf("\n");
			}
		}
	}

		if (test) {
		const int testC = 20;
		char testString[MAXSTRINGSIZE];
		int testNums[testC];
		srand(time(NULL));
		randomArray(testC, testNums, -9999, 9999);
		const int basesC = 5;
		int bases[] = { 2, 8, 10, 16, 32 };
		int i, n, j;
		printf(" base: ");
		for (n = 0; n < basesC; n++) {
			for (j = (bases[n] > 2 ? 6 : 13) - (bases[n] > 9 ? 1 : 0); j >= 0; j--) {
				printf(" ");
			}
			printf("%d", bases[n]);
		}
		printf("\n");
		for (i = 0; i < 54; i++) {
			printf("_");
		}
		printf("\n\n");
		for (i = 0; i < testC; i++) {
			printf("%5d: ", testNums[i]);
			for (n = 0; n < basesC; n++) {
				intToStringBaseN(testNums[i], bases[n], testString);
				for (j = (bases[n] > 2 ? 7 : 14) - strlen(testString); j >= 0; j--) {
					printf(" ");
				}
				printf("%s", testString);
			}
			printf("\n");
		}
		for (i = 0; i < 54; i++) {
			printf("_");
		}
		printf("\n\n");
		//Test with lowest negative int
		const int intLowerLimit = (int)-(pow(2.0, sizeof(int) * 8) / 2);
		intToStringBaseN(intLowerLimit, 10, testString);
		printf("%d\t%s\n", intLowerLimit, testString);
	}

}

char intToChar(int myInt)
{
	if (myInt > 36) {
		fprintf(stderr, "ERROR: Base > 36 not suported\n");
		return EOF;
	}
	if (myInt < 10) {
		return myInt + '0';
	} else {
		return myInt - 10 + 'A';
	}
}

int intToStringBaseN(int myInt, int base, char myString[])
{
	if (base > 36) {
		fprintf(stderr, "ERROR: Base > 36 not supported\n");
		return -1;
	}
	int numLength = 0;
	BOOL neg = FALSE;
	if (myInt < 0) {
		neg = TRUE;
		myString[0] = '-';
		numLength++;
	}
	//get num length in decimal representation
	int tempNum = myInt;
	for (; tempNum != 0; tempNum /= base, numLength++) {
	}
	int i;
	for (i = 0; i < (numLength - (neg ? 1 : 0)); myInt /= base, i++) {
		myString[numLength - 1 - i] = intToChar((myInt % base) * (myInt % base < 0 ? -1 : 1));
	}
	myString[numLength] = '\0'; //Close string
	return numLength;
}
