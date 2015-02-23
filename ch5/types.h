#ifndef TYPES_H
#define TYPES_H

typedef enum { CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, LONGDOUBLE, UNKNOWN, GREATERTHANLONGDOUBLE } TYPE;

#define TYPES__TYPESC 7 //Number of types

TYPE getTYPEFromSize(int size);
TYPE getTYPEFromString(char* typeStr);
int isStringTYPE(char* myString);

#define SIZEOF(myTYPE)	(TYPES__getTypeSize(myTYPE))
int TYPES__getTypeSize(TYPE myTYPE);

#define TYPES__MAXTYPENAMELENGTH 10 /*  LONGDOUBLE */
extern char TYPES__TYPESStr[TYPES__TYPESC][TYPES__MAXTYPENAMELENGTH];

#define getStringFromTYPE(myTYPE) (TYPES__TYPESStr[(int)myTYPE])

#endif /*  TYPES_H */
