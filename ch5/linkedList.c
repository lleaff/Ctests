#define DEBUG
#include "../debug.h"

#include "types.h"
#include <stdio.h>
#include <stdlib.h> /*  malloc() */
#include <string.h>
#include <stdarg.h>
/*  CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, LONGDOUBLE, UNKNOWN, GREATERTHANLONGDOUBLE */

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

typedef struct LL {
	struct Link* curr;
	int length;
} LL;

typedef struct Link {
	struct Link* prev;
	struct Link* next;
	TYPE type;
	char elem[];
} Link;

static void resolveTypeAndSizeFromString(char* myString, int myStringValue, TYPE* type, int* size);
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap);

Link* LL__newLink(int size, void* elemmem, Link* prev)
{
	Link* myLink = (Link*)malloc(size + sizeof(Link));
	memcpy(myLink->elem, elemmem, size);
	myLink->prev = prev;
	myLink->next = NULL;
	if (prev != NULL) {
		prev->next = myLink; /*  Set itself as 'next' of previous Link */
	}
	return myLink;
}

#define LASTARGID_LLD 242319377175715117
static const long double LastArgId_LLD = LASTARGID_LLD;
#define newLL(typeOrSize, ...)	LL__newLL(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)

LL LL__newLL(char* typeOrSize, int typeOrSizeValue, ...)
{
	DEBUGP("typeOrSize=\"%s\"\n", typeOrSize)
	TYPE type;
	int size;
	resolveTypeAndSizeFromString(typeOrSize, typeOrSizeValue, &type, &size);

	va_list ap;
	va_start(ap, typeOrSizeValue);
	char elemmem[size];

	Link* prev = NULL;
	int length;
	for (length = 0; initElemmem(&type, &elemmem, &ap); length++) {
		LL__newLink(size, &elemmem, prev);
	}

	LL myLinkedList;
	myLinkedList.curr = prev;
	myLinkedList.length = length;
	return myLinkedList;
}

/*  Returns 0 if there is no argument left */
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap)
{
	if (*(long double*)ap == LastArgId_LLD) { /*  Assuming ap is a pointer to the args stored contiguously */
		return 0; //Last argument //TODO: <===This is never reached
	}
	switch (*type) {
		case CHAR:		*(long double*)elemmem = va_arg(ap, int);
						/* 'char' is promoted to 'int' when passed through '...' */
					break;
		case INT:		*(long double*)elemmem = va_arg(ap, int);
					break;
		case SHORT:		*(long double*)elemmem = va_arg(ap, int);
						/* 'short' is promoted to 'int' when passed through '...' */
					break;
		case LONG:		*(long double*)elemmem = va_arg(ap, long);
					break;
		case FLOAT:		*(long double*)elemmem = va_arg(ap, double);
						/* 'float' is promoted to 'double' when passed through '...' */
					break;
		case DOUBLE:	*(long double*)elemmem = va_arg(ap, double);
					break;
		case LONGDOUBLE:*(long double*)elemmem = va_arg(ap, long double);
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

static void resolveTypeAndSizeFromString(char* myString, int myStringValue, TYPE* type, int* size)
{
	if (tryGetIntFromString(myString, size)) {	/*	String is int	*/
		*type = getTYPEFromSize(*size);
	} else if (isStringTYPE(myString)) {		/*	String is type	*/
		*type = getTYPEFromString(myString);
		*size = SIZEOF(*type);
	} else {									/*  Get size from myStringValue instead */
		*size = myStringValue;
		*type = getTYPEFromSize(*size);
	}
}

int main()
{
	LL intList = newLL(sizeof(int), 64, 2, 32, 8, 16, 4, 1);
	printf("%d\n", (int)(intList.curr->elem));
}
