#ifndef TYPES_H
#define TYPES_H

typedef enum { CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, LONGDOUBLE, UNKNOWN, GREATERTHANLONGDOUBLE } TYPE;

#define TYPES__TYPESC 7 //Number of types

int TYPES__typesSizes[TYPES__TYPESC] = {
	(int)sizeof(char),
	(int)sizeof(short),
	(int)sizeof(int),
	(int)sizeof(long),
	(int)sizeof(float),
	(int)sizeof(double),
	(int)sizeof(long double),
};

TYPE getType(int size);

#define SIZEOF(myTYPE)	(TYPES__typesSizes[myTYPE])

#endif /*  TYPES_H */
