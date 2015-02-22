#include <stdio.h>
#include <stdarg.h>
#include "types.h"
/*  CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, LONGDOUBLE, UNKNOWN, GREATERTHANLONGDOUBLE */

typedef struct LL {
	struct LL* prev;
	struct LL* next;
	char elem[];
} LL;

#define newLL(firstElem, ...)	LL__newLL(&(firstElem), __VA_ARGS__)

LL LL__newLL(int size, ...)
{
	va_list ap;
	va_start(ap, size);
	char elemmem[size];
	TYPE type = getType(size);
	switch (type) {
		case CHAR:		*elemmem = va_arg(ap, char);
					break;
		case INT:		*elemmem = va_arg(ap, int);
					break;
		case SHORT:		*elemmem = va_arg(ap, short);
					break;
		case LONG:		*elemmem = va_arg(ap, long);
					break;
		case FLOAT:		*elemmem = va_arg(ap, float);
					break;
		case DOUBLE:	*elemmem = va_arg(ap, double);
					break;
		case LONGDOUBLE:*elemmem = va_arg(ap, long double);
					break;
		default:	break;
	}

}

int main()
{
	LL intList = LL__newLL(sizeof(int), 1, 2, 4, 8, 16, 32, 64);
}
