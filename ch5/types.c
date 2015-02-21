#include "types.h"
#include <stdio.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /*  BOOL_TYPE */

TYPE getType(int size)
{
	if (size > typesSizes[LONGDOUBLE]) {
		return GREATERTHANLONGDOUBLE;
	}
	int i;
	for (i = 0; i < TYPES__TYPESC; ++i) {
		if (size == typesSizes[i]) {
			return (TYPE)i;
		}
	}
	return UNKNOWN;
}
