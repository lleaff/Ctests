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

#define LinkedList LL //Verbose form

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



/* ========================================================================	*
 * 							Initializing the struct							*
 * ======================================================================== */
static void resolveTypeAndSizeFromString(char* myString, int myStringValue, TYPE* type, int* size);
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap);

Link* LL__newLink(int size, void* elemmem, Link* prev)
{
	Link* myLink = (Link*)malloc(sizeof(Link) + size); /*  Size of the empty struct + size of elem */
	memcpy(myLink->elem, elemmem, size);
	myLink->prev = prev;
	myLink->next = NULL;
	if (prev != NULL) {
		prev->next = myLink; /*  Set itself as 'next' of previous Link */
	}
	return myLink;
}

#define LASTARGID_LLD 242319717654231400
static const long long LastArgId_LLD = LASTARGID_LLD;
#define newLL(typeOrSize, ...)	LL__newLL(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)

LL LL__newLL(char* typeOrSize, int typeOrSizeValue, ...)
{
	DEBUGP("typeOrSize=\"%s\"\n", typeOrSize)
	TYPE type;
	int size;
	resolveTypeAndSizeFromString(typeOrSize, typeOrSizeValue, &type, &size);
	DEBUGP("size=%d\ttype=%d\n", size, (int)type)

	va_list ap;
	va_start(ap, typeOrSizeValue);
	char elemmem[size];

	Link* prev = NULL;
	int length;
	for (length = 0; initElemmem(&type, &elemmem, &ap); length++) {
		DEBUGP("*(%s*)elemmem=%d\n", TOLOWER(getStringFromTYPE(type)), *(int*)elemmem)
		prev = LL__newLink(size, elemmem, prev);
	}

	LL myLinkedList;
	myLinkedList.curr = prev;
	DEBUGP("&&& myLinkedList.curr=%p\n", myLinkedList.curr)
	DEBUGP("    myLinkedList.curr->elem=%d\n", (int)((myLinkedList.curr)->elem))
	myLinkedList.length = length;
	return myLinkedList;
}

/*  Returns 0 if there is no argument left */
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap)
{
	switch (*type) {
		case CHAR:		/* 'char' is promoted to 'int' when passed through '...' */
		case SHORT:		/* 'short' is promoted to 'int' when passed through '...' */	
		case INT:		*(int*)elemmem = va_arg(*ap, int);
					break;
		case LONG:		*(long*)elemmem = va_arg(*ap, long);
					break;
		case FLOAT:		/* 'float' is promoted to 'double' when passed through '...' */
		case DOUBLE:	*(double*)elemmem = va_arg(*ap, double);
					break;
		case LONGDOUBLE:*(long double*)elemmem = va_arg(*ap, long double);
					break;
		default:
					break;
	}
	if (**(long long**)ap == LastArgId_LLD) {
		va_end(*ap);
		DEBUGP("------LastArg------\n")
		return 0; //Last argument
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

/* ===================== END  Initializing the struct ===================== */

int main()
{
	LL intList = newLL(sizeof(int), 64, 32, 16, 8, 4, 2, 1);
	printf("length=%d\n", intList.length);
	DEBUGP("&&& intList.curr=%p\n", intList.curr)
	printf("intList.curr->elem=%d\n", *(int*)((intList.curr)->elem));

	Link currLink = *(intList.curr);
	printf("Link currLink = *(intList.curr);\n");
	printf("currLink.elem=%d\n", *(int*)currLink.elem);

	*(int*)(intList.curr)->elem = 555;
	printf(">>>>*(int*)(intList.curr)->elem = 555;\n");

	printf("intList.curr->elem=%d\n", (int)((intList.curr)->elem));
	printf("((intList.curr->prev))->elem=%d\n", *(int*)(intList.curr)->elem);
}
