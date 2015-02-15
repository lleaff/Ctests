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

int isStringType(void *ptr);

#define strlen(string) String__strlength(&(string))
int String__strlength(void *ptr);

String newString(int length, char *cStyleString);
int CopyString(String destination, void *origin);

#endif /*  STRINGTYPE_H */
