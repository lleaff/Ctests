#ifndef TYPES_H
#define TYPES_H

typedef enum { CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, LONGDOUBLE, UNKNOWN, GREATERTHANLONGDOUBLE } TYPE;

#define TYPES__TYPESC 7 //Number of types

TYPE getTYPEFromSize(int size);
TYPE getTYPEFromString(char* typeStr);
int isStringTYPE(char* myString);

#define SIZEOF(myTYPE)	(TYPES__getTypeSize(myTYPE))
int TYPES__getTypeSize(TYPE myTYPE);

#endif /*  TYPES_H */
