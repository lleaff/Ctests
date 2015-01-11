#include <stdio.h>

#define MAXSTRINGLENGTH 10000

typedef enum { FALSE, TRUE } BOOL;

char reverseCaseChar(char character)
{
	if (character >= 'A' && character <= 'Z') {
		return (character - 'A' + 'a');
	} else if (character >= 'a' && character <= 'z') {
		return (character - 'a' + 'A');
	} else {
		return character;
	}
}

BOOL reverseCaseString(char myString[])
{
	int i;
	for (i = 0; myString[i] != '\0' && i < MAXSTRINGLENGTH; i++) {
		myString[i] = reverseCaseChar(myString[i]);
	}
	if (i > MAXSTRINGLENGTH) {
		return FALSE; //ERROR: String too long
	} else {
		return TRUE; //Success
	}
}

int main()
{
	char testString1[] = "This is a GREAT string. Definitel_54$ù^*Gl3";
	printf("%s\n", testString1);
	if (reverseCaseString(testString1)) {
		printf("%s\n", testString1);
	} else {
		printf("ERROR");
		return 1;
	}
	return 0;
}
