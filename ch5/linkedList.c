#include <stdio.h>
#include <stdlib.h> /*  malloc() */
#include <string.h>
#include <stdarg.h>
#include "types.h"
/*  CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, LONGDOUBLE, UNKNOWN, GREATERTHANLONGDOUBLE */

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

typedef struct Link {
	struct Link* prev;
	struct Link* next;
	char elem[];
} Link;

static void resolveTypeAndSizeFromString(char* myString, TYPE* type, int* size);
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap);

Link* LL__newLink(int size, void* elemmem, Link* prev)
{
	Link* myLink = (Link*)malloc(size + sizeof(Link));
	memcpy(myLink->elem, elemmem, size);
	return myLink;
}

#define newLL(typeOrSize, ...)	LL__newLL(#typeOrSize, __VA_ARGS__, LASTARGID_LLD)

Link LL__newLL(char* typeOrSize, ...)
{
	TYPE type;
	int size;
	resolveTypeAndSizeFromString(typeOrSize, &type, &size);

	va_list ap;
	va_start(ap, typeOrSize);
	char elemmem[size];

	Link* prev = NULL;
	while (initElemmem(&type, &elemmem, &ap)) {
		LL__newLink(size, &elemmem, prev);
	}

}

#define LASTARGID_LLD 242319377175715117
static const long double LastArgId_LLD = LASTARGID_LLD;
/*  Returns 0 if there is no argument left */
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap)
{
	//TODO: That won't work because va_arg will push ap {sizeof(long double)} B instead of {sizeof(type)} B
	long double va_argBuffer = va_arg(ap, long double);
	if (va_argBuffer == LastArgId_LLD) {
		return 0; //Last argument
	}
	switch (*type) {
		case CHAR:		*(long double*)elemmem = (char)va_argBuffer;
					break;
		case INT:		*(long double*)elemmem = (int)va_argBuffer;
					break;
		case SHORT:		*(long double*)elemmem = (short)va_argBuffer;
					break;
		case LONG:		*(long double*)elemmem = (long)va_argBuffer;
					break;
		case FLOAT:		*(long double*)elemmem = (float)va_argBuffer;
					break;
		case DOUBLE:	*(long double*)elemmem = (double)va_argBuffer;
					break;
		case LONGDOUBLE:*(long double*)elemmem = (long double)va_argBuffer;
					break;
		default:	break;
	}
	return 1; //Success
}

//Returns -1 if the char doesn't represent a digit
static int tryGetIntFromChar(char digit)
{
	if (digit >= '0' && digit <= '9') {
		return digit - '0'; 
	} else {
		return -1; //Not a digit
	}
}

//Returns 1 if successful, 0 if string doesn't convert to an int
static int tryGetIntFromString(char* myString, int* convertedInt)
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

static void resolveTypeAndSizeFromString(char* myString, TYPE* type, int* size)
{
	if (tryGetIntFromString(myString, size)) {	/*	String is int	*/
		*type = getTYPEFromSize(*size);
	} else {									/*	String is type	*/
		*type = getTYPEFromString(myString);
		*size = SIZEOF(*type);
	}
}

int main()
{
	LL intList = LL__newLL(sizeof(int), 1, 2, 4, 8, 16, 32, 64);
}
