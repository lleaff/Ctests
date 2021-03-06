#include "types.h"
#include <string.h> /*  memcpy() */

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /*  BOOL_TYPE */

char TYPES__TYPESStr[TYPES__TYPESC][TYPES__MAXTYPENAMELENGTH] = {
			"CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "LONGDOUBLE" };

int TYPES__typesSizes[TYPES__TYPESC] = {
	(int)sizeof(char),
	(int)sizeof(short),
	(int)sizeof(int),
	(int)sizeof(long),
	(int)sizeof(float),
	(int)sizeof(double),
	(int)sizeof(long double),
};

TYPE getTYPEFromSize(int size)
{
	if (size > TYPES__typesSizes[LONGDOUBLE]) {
		return GREATERTHANLONGDOUBLE;
	}
	int i;
	for (i = 0; i < TYPES__TYPESC; ++i) {
		if (size == TYPES__typesSizes[i]) {
			return (TYPE)i;
		}
	}
	return UNKNOWN;
}

TYPE getTYPEFromString(char* typeStr)
{
	int i;
	for (i = 0; i < TYPES__TYPESC; ++i) {
		if (!strcmp(TYPES__TYPESStr[i], typeStr)) {
			return (TYPE)i;
		}
	}
	return UNKNOWN;
}

int isStringTYPE(char* myString)
{
	if (getTYPEFromString(myString) == UNKNOWN) {
		return 0;
	} else {
		return 1;
	}
}

int TYPES__getTypeSize(TYPE myTYPE)
{
	return TYPES__typesSizes[(int)myTYPE];
}
