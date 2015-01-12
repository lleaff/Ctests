#include "stringCompare.h"
#include <stdio.h>

BOOL stringCompare(char string1[], char string2[])
{
	int i;
	for (i = 0; string1[i] != '\0' && string2[i] != '\0'; i++) {
		if (string1[i] != string2[i]) {
			return FALSE;
		}
	}
	return TRUE;
}

int main() 
{
	return 0;
}
