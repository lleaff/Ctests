#include <stdio.h>

#define DEBUG

#define FALSE 0
#define TRUE 1

#ifndef SQUEEZE_FUNC
#define SQUUEZE_FUNC
int squeeze(char string1[], char string2[])
{
	int i, j, k;
	int match = FALSE;
	for (i = j = 0; string1[j] != '\0'; match = FALSE) {
		for (k = 0; string2[k] != '\0'; k++) {
			if (string1[j] == string2[k]) {
				match = TRUE;
				j++;
				break;
			}
		}
		string1[i] = string1[j];
		if (!match) {
			i++, j++;
		}
	}
	string1[i] = '\0';
	return 0; //Success
}
#endif


int main()
{
	char testString1[] = "i'm a tree cat yes cat";
	char testString2[] = "cat";
	printf("remove any char in\n       \t%s\n   from\t%s.\n", testString2, testString1);
	squeeze(testString1, testString2);
	printf(">>>>>>>\t%s.\n", testString1);
}
