#ifndef STRINGTYPE_H
#define STRINGTYPE_H
#include <stdlib.h> //For NULL pointer identifier
#include <string.h>

#define strlen(string) String__strlength(&(string))

typedef struct String {
	double stringTypeID;
	char *Chars;
	int Length;
	int LengthLimit;
} String;

String newString(int length, char *cStyleString);
int CopyString(String destination, void *origin);
int isStringType(void *ptr);

#endif /*  STRINGTYPE_H */
