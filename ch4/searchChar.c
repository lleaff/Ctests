#include "searchChar.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXSTRINGSIZE 1000
#define OUTBUFFERWIDTH 78

typedef enum { FALSE, TRUE } BOOL;

int randInt(int lowerLimit, int upperLimit);
int printfExcerpt(char str[], int maxLength, int focusedIndex);

int stringToInt(char myString[])
{
	int i;
	if (myString[0] == '\0') {
		return -1; //Error empty string
	}
	int num = 0;
	for (i = 0; myString[i] != '\0'; i++) {
		num = (num * 10) + (myString[i] - '0');
	}
	return num;
}

int main(int argc, char **argv)
{
	BOOL test = FALSE;
	int testC;
	char searchedChar;
	char containingString[MAXSTRINGSIZE];
	if (argc == 1) {
		scanf("%c", &searchedChar);
		scanf("%s", containingString);
	} else if (argc <= 3) {
		if (!strcmp(argv[1], "--test")) {
			test = TRUE;
			testC = 6;
			if (argc == 3) {
				testC = stringToInt(argv[2]);
			}
		}
	}

	printf("%d", searchChar(searchedChar, containingString));

	if (test) {
		char testString[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
		srand(time(NULL));
		char searchedChar;
		int charIndex;
		int arrowPos;

		printf("Find rightmost occurence of characters in this text:\n %s\n\n", testString);
		int i;
		for (i = 0; i < testC; i++) {
			searchedChar = randInt('a', 'z');
			printf("?  %c\n", searchedChar);
			charIndex = searchChar(searchedChar, testString);
			if (charIndex != -1) {
			arrowPos = printfExcerpt(testString, OUTBUFFERWIDTH, charIndex);
			printf("\n");
			for (; arrowPos > 0; arrowPos--) {
				printf(" ");
			}
			printf("^\n");
			} else {
				printf("Not found\n");
			}
		}
	}
}

int searchChar(char searched, char str[])
{
	int i = strlen(str) - 1;
	for (; i >= 0; i--) {
		if (str[i] == searched) {
			return i;
		}
	}
	return -1;
}

void printfFromTo(char str[], int beginning, int end)
{
	for (; beginning <= end && str[beginning] != '\0'; beginning++) {
		putchar(str[beginning]);
	}
}

//Returns the position of the focusedIndex in the new printed text
int printfExcerpt(char str[], int maxLength, int focusedIndex)
{
	char separatorA[] = "<< ";
	char separatorB[] = " >>";
	//char separatorB[strlen(separatorA)];	// To have separatorA & B
	//strcpy(separatorB, separatorA);		//  be the same
	maxLength -= strlen(separatorA) + strlen(separatorB);

	int len = strlen(str);
	int lowerI, higherI, buffer;

	lowerI = focusedIndex - (maxLength / 2);
	higherI = focusedIndex + (maxLength - (maxLength / 2));
	if (lowerI < 0) {
		buffer = -lowerI;
		lowerI = 0;
		higherI = (higherI + buffer > len) ? len : higherI + buffer;
	} else if (higherI > len) {
		buffer = len - higherI;
		higherI = len;
		lowerI = (lowerI + buffer < 0) ? 0 : lowerI + buffer;
	}


	printf("%s", separatorA);
	printfFromTo(str, lowerI, higherI);
	printf("%s", separatorB);

	return (focusedIndex - lowerI + strlen(separatorA));
}

int randInt(int lowerLimit, int upperLimit)
{
	return (((upperLimit - lowerLimit) * rand()) / RAND_MAX) + lowerLimit;
}
