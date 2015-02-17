#ifndef STRINGTYPE_H
#define STRINGTYPE_H
#include <stdlib.h> //For NULL pointer identifier
#include <string.h>

typedef struct String {
	short stringTypeID;
	char *Chars;
	int Length;
	int LengthLimit;
} String;

String newString(int length, char *cStyleString);

void changeStringLength(String myString, int lengthLimit);
int isStringType(void *ptr);
#define strlen(string) String__strlength(&(string))
int String__strlength(void *ptr);
int CopyString(String destination, void *origin);
int compareStrings(String str1, String str2);

#endif /*  STRINGTYPE_H */
