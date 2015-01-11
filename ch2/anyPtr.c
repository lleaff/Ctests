#include <stdio.h>
 
char *firstOccurenceOfAnyChar(char myString[], char characters[])
{
	int i, j;
	for (i = 0; myString[i] != '\0'; i++){
		for (j = 0; characters[j] != '\0'; j++) {
			if (myString[i] == characters[j]) {
				return &myString[i];
			}
		}
	}
	return NULL; //ERROR: No occurence
}

int main()
{
	char testString1[] = "This is a test string and it's going to be tested";
	char testString2[] = "tzwi";
	char *firstOccurence = firstOccurenceOfAnyChar(testString1, testString2);
	printf("First occurence of any character \"%s\" in\n\"%s\"\n", testString2, testString1);
	int index = firstOccurence - testString1;
	for (; index + 1 > 0; index--) {
		printf(" ");
	}
	printf("^\n");
	return 0;
}
