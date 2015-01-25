#include "expand.h"
#include <stdio.h>
#include <string.h>

#define MAXSTRINGSIZE 2000

typedef enum { FALSE, TRUE } BOOL;

int stringToInt(char myString[]);

int main(int argc, char *argv[])
{
	char shorthand[MAXSTRINGSIZE];
	char expanded[MAXSTRINGSIZE];
	if (argc > 1) {
		if (!strcmp(argv[1], "--test")) {
			strcpy(shorthand, "-a-d <[-a\\-d] 5-20 <[5\\-20]");
			printf("%s\n", shorthand);
		} else {
			strcpy(shorthand, argv[1]);
		}
	} else {
		printf("Please input something to expand in a notation like this: a-z or 0-9\n");
		scanf("%s", shorthand);
	}

	if (expand(shorthand, expanded)) {
		printf("%s\n", expanded);
	} else {
		printf("Nothing to expand\n");
	}

}

BOOL isDigit(char myChar)
{
	if (myChar >= '0' && myChar <= '9') {
		return TRUE;
	} else {
		return FALSE;
	}
}

BOOL isLowcaseLatinLetter(char myChar)
{
	if (myChar >= 'a' && myChar <= 'z') {
		return TRUE;
	} else {
		return FALSE;
	}
}

BOOL isUppercaseLatinLetter(char myChar)
{
	if (myChar >= 'A' && myChar <= 'Z') {
		return TRUE;
	} else {
		return FALSE;
	}
}

typedef enum { other, digit, lowcaseLatinLetter, uppercaseLatinLetter } charTypeName;

typedef struct {
	charTypeName type;
	char lowestChar;
	char highestChar;
} charType;

charType getCharType(char myChar)
{
	charType myCharType;
	myCharType.type = other;
	if (isDigit(myChar)) {
		myCharType.type = digit;
		myCharType.lowestChar = '0';
		myCharType.highestChar = '9';
	} else if (isLowcaseLatinLetter(myChar)) {
		myCharType.type = lowcaseLatinLetter;
		myCharType.lowestChar = 'a';
		myCharType.highestChar = 'z';
	} else if (isUppercaseLatinLetter(myChar)) {
		myCharType.type = uppercaseLatinLetter;
		myCharType.lowestChar = 'A';
		myCharType.highestChar = 'Z';
	} 
	return myCharType;
}

//input[] can't be the same as output[]
int expand(char input[], char output[])
{
	int expansionC = 0;

	char target;
	int i, j, k;
	charType firstCharType, secondCharType;
	for (i = j = 0; input[i] != '\0'; i++, j++) {
		//Detect shorthand notation
		if (input[i] == '-' && i > 0 && input[i + 1] != '\0') {
			firstCharType = getCharType(input[i - 1]);
			secondCharType = getCharType(input[i + 1]);
			if (firstCharType.type == secondCharType.type) {
				expansionC++;
				for (k = 1, target = input[i + 1]; output[j - 1] != target; j++, k++) {
					output[j] = input[i - 1] + k;
				}
				j--, i++;
			}
		} else {
			output[j] = input[i];
		}
	}
	return expansionC;
}


int charToDigit(char myChar)
{
	if (myChar >= '0' && myChar <= '9') {
		return myChar - '0';
	} else {
		return -1; //Not a digit
	}
}

int stringToInt(char myString[])
{
	int i;
	int myInt = 0, digit;
	for(i = 0; myString[i] != '0'; i++) {
		if ((digit = charToDigit(myString[i])) >= 0) {
			myInt = (myInt * 10) + digit;
		}
	}
	return myInt;
}
