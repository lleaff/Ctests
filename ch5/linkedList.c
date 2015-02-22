#include <stdio.h>
#include <stdarg.h>
#include "types.h"
/*  CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, LONGDOUBLE, UNKNOWN, GREATERTHANLONGDOUBLE */

typedef struct LL {
	struct LL* prev;
	struct LL* next;
	char elem[];
} LL;

void resolveTypeAndSizeFromString(char* myString, TYPE* type, int* size);

#define newLL(typeOrSize, ...)	LL__newLL(#typeOrSize, __VA_ARGS__)

LL LL__newLL(char* typeOrSize, ...)
{
	TYPE type;
	int size;
	resolveTypeAndSizeFromString(typeOrSize, &type, &size);

	va_list ap;
	va_start(ap, typeOrSize);
	char elemmem[size];
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

//Returns -1 if the char doesn't represent a digit
int tryGetIntFromChar(char digit)
{
	if (digit >= '0' && digit <= '9') {
		return digit - '0'; 
	} else {
		return -1; //Not a digit
	}
}

//Returns 1 if successful, 0 if string doesn't convert to an int
int tryGetIntFromString(char* myString, int* convertedInt)
{
	*convertedInt = 0;
	int sign = 1;
	if (*myString == '-') {
		sign = -1;
		++myString;
	}
	int digit;
	for (; *myString != '\0'; myString++) {
		if ((digit = tryGetIntFromChar(*myString)) >= 0) {
			*convertedInt += digit;
		} else {
			return 0; //Error string doesn't convert to an int
		}
	}
	*convertedInt *= sign;
	return 1; //Success
}

void resolveTypeAndSizeFromString(char* myString, TYPE* type, int* size)
{
	if (tryGetIntFromString(myString, size)) {	/*	String is int	*/
		*type = getTypeFromSize(*size);
	} else {									/*	String is type	*/
		*type = getTypeFromString(myString);
		*size = SIZEOF(*type);
	}
}

int main()
{
	LL intList = LL__newLL(sizeof(int), 1, 2, 4, 8, 16, 32, 64);
}
