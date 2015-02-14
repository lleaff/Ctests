#ifndef STRINGTYPE_H
#define STRINGTYPE_H
#include <stdlib.h> //For NULL pointer identifier

typedef struct {
	double stringTypeID;
	char *Chars;
	int Length;
	int LengthLimit;
} String;

String newString(int length, char *cStyleString);
int CopyString(String destination, void *otherString);

#define strlen(ptr)	strlen__flexible(&ptr)
int strlen__flexible(void *ptr);

#endif /*  STRINGTYPE_H */
