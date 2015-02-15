#include <stdio.h>
#include <string.h>

void strcatPtr(char *firstString, char *secondString, char *destination)
{
	if (firstString != destination) {
		strcpy(destination, firstString);
	}
	strcpy((destination + strlen(firstString) - 1), secondString);
}

int main()
{
	char testStr1[15*2] = "This is string1";
	char testStr2[] = "This is string2";
	char testStr3[strlen(testStr1) + strlen(testStr2)];
	testStr3[0] = '\0';

	printf("str1: %s\nstr2: %s\nstr3: %s\n", testStr1, testStr2, testStr3);
	strcatPtr(testStr1, testStr2, testStr3);
	printf("strcatPtr(testStr1, testStr2, testStr3);\n");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", testStr1, testStr2, testStr3);
	strcatPtr(testStr1, testStr2, testStr1);
	printf("strcatPtr(testStr1, testStr2, testStr1);\n");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", testStr1, testStr2, testStr3);

	return 0;
}
