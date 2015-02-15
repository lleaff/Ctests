#ifndef STRINGTYPE_H
#define STRINGTYPE_H
#include <stdlib.h> //For NULL pointer identifier
#include <string.h>

typedef struct String {
	double stringTypeID;
	char *Chars;
	int Length;
	int LengthLimit;
} String;

String newString(int length, char *cStyleString);

int isStringType(void *ptr);
#define strlen(string) String__strlength(&(string))
int String__strlength(void *ptr);
int CopyString(String destination, void *origin);
int compareStrings(String str1, String str2);

#endif /*  STRINGTYPE_H */
