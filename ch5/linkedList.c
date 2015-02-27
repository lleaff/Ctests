#include "../debug.h"

#include "linkedList.h"
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

#ifdef DEBUG
static inline void* mallocdebug(int size)
{
	void* returnptr = malloc(size);
	if (!returnptr) {
		fprintf(stderr, "ERROR: malloc failed, can't allocate %d B\n", size);
	} else {
		fprintf(stderr, "DEBUG: malloc success, allocated %d B\n", size);
	}
	return returnptr;
}
#define malloc(size)	mallocdebug(size)
#endif /* DEBUG */

/* ========================================================================	*
 * 								Initialization								*
 * ======================================================================== */
LL__Link* LL__newLink(int size, void* elemMem, LL__Link* prev);
static void resolveTypeAndSizeFromString(char* myString, int myStringValue, TYPE* type, int* size);
static int fillElemMem(const TYPE* type, void* elemMem, va_list* ap);

#define LASTARGID_LLD 242319717654231400
static const long long LastArgId_LLD = LASTARGID_LLD;

#ifndef LL__CallLLnew
#define LL__CallLLnew(typeOrSize, ...)	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
#endif /* LL__CallLLnew */

LL LL__LLnew(char* typeOrSize, int typeOrSizeValue, ...)
{
	TYPE type;
	int size;
	resolveTypeAndSizeFromString(typeOrSize, typeOrSizeValue, &type, &size);

	va_list ap;
	va_start(ap, typeOrSizeValue);
	char elemMem[size];

	LL__Link* prev = NULL;
	int length;
	for (length = 0; fillElemMem(&type, &elemMem, &ap); length++) {
		prev = LL__newLink(size, elemMem, prev);
	}

	LL myLinkedList;
	myLinkedList.curr = prev;
	myLinkedList.length = length;
	return myLinkedList;
}

LL__Link* LL__newLink(int size, void* elemMem, LL__Link* prev)
{
	LL__Link* myLink = (LL__Link*)malloc(sizeof(LL__Link) + size); /*  Size of the empty struct + size of elem */
	memcpy(myLink->elem, elemMem, size);
	myLink->prev = prev;
	myLink->next = NULL;
	if (prev != NULL) {
		prev->next = myLink; /*  Set itself as 'next' of previous Link */
	}
	return myLink;
}

/*  Returns 0 if there is no argument left */
inline static int fillElemMem(const TYPE* type, void* elemMem, va_list* ap)
{
	if (**(long long**)ap == LastArgId_LLD) {
		va_end(*ap);
		return 0; //Last argument
	}
	switch (*type) {
		case CHAR:			/* 'char' is promoted to 'int' when passed through '...' */
		case SHORT:			/* 'short' is promoted to 'int' when passed through '...' */	
		case INT:			*(int*)elemMem = va_arg(*ap, int);
					break;
		case LONG:			*(long*)elemMem = va_arg(*ap, long);
					break;
		case FLOAT:			/* 'float' is promoted to 'double' when passed through '...' */
		case DOUBLE:		*(double*)elemMem = va_arg(*ap, double);
					break;
		case LONGDOUBLE:	*(long double*)elemMem = (long double)va_arg(*ap, long double); //<= SEGFAULT here when compiled with gcc, but not with clang
					break;
		default:
					break;
	}
	return 1; //Success
}

//Returns -1 if the char doesn't represent a digit
inline static int tryGetIntFromChar(char digit)
{
	if (digit >= '0' && digit <= '9') {
		return digit - '0'; 
	} else {
		return -1; //Not a digit
	}
}

//Returns 1 if successful, 0 if string doesn't convert to an int
inline static int tryGetIntFromString(char* myString, int* convertedInt)
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

inline static void resolveTypeAndSizeFromString(char* myString, int myStringValue, TYPE* type, int* size)
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

/* =====================      END  Initialization 	  ===================== */

/* ========================================================================	*
 * 									Read									*
 * ======================================================================== */
#ifndef LLread
/* Usage: LLread(type)(myLL) */
#define LL__READLLCALLPASTER(type)	LL__read ## type ## LL
#define LLread(type)	LL__READLLCALLPASTER(type)
#endif /* LLread */

char LL__readcharLL(LL myLL)
{
	return *(char*)((myLL.curr)->elem);
}
short LL__readshortLL(LL myLL)
{
	return *(short*)((myLL.curr)->elem);
}
int LL__readintLL(LL myLL)
{
	return *(int*)((myLL.curr)->elem);
}
long LL__readlongLL(LL myLL)
{
	return *(long*)((myLL.curr)->elem);
}
float LL__readfloatLL(LL myLL)
{
	return *(float*)((myLL.curr)->elem);
}
double LL__readdoubleLL(LL myLL)
{
	return *(double*)((myLL.curr)->elem);
}
long double LL__readlongdoubleLL(LL myLL)
{
	return *(long double*)((myLL.curr)->elem);
}

BOOL LL__isHead(LL* myLL)
{
	return (myLL->curr->prev == NULL);
}
BOOL LL__isTail(LL* myLL)
{
	return (myLL->curr->next == NULL);
}

LL__Link LL__getLink(LL* myLL)
{
	return *(myLL->curr);
}

LL__Link LL__nextLink(LL* myLL)
{
	return *(myLL->curr->next);
}
LL__Link LL__prevLink(LL* myLL)
{
	return *(myLL->curr->prev);
}
LL__Link LL__nextNLinks(LL* myLL, int n)
{
	LL__Link* ptr = myLL->curr;
	while ((ptr = ptr->next) && --n)
		;
	return *ptr;
}
LL__Link LL__prevNLinks(LL* myLL, int n)
{
	LL__Link* ptr = myLL->curr;
	while ((ptr = ptr->prev) && --n)
		;
	return *ptr;
}
LL__Link LL__readN(LL* myLL, int n)
{
	if (n > 0) {
		return LL__nextNLinks(myLL, n);
	} else if (n < 0) {
		return LL__prevNLinks(myLL, n);
	} else {
		return *(myLL->curr);
	}
}


/* ==================  			END  Read				 ================== */

/* ========================================================================	*
 * 									Move									*
 * ======================================================================== */

int LL__next(LL* myLL)
{
	if (myLL->curr->next != NULL) {
		myLL->curr = myLL->curr->next;
		return 1; //Success
	} else {
		return 0; //Last link
	}
}
int LL__prev(LL* myLL)
{
	if (myLL->curr->prev != NULL) {
		myLL->curr = myLL->curr->prev;
		return 1; //Success
	} else {
		return 0; //First link
	}
}


int LL__nextN(LL* myLL, int n)
{
	for (; n > 0; --n) {
		if (!LL__next(myLL)) {
			break;
		}
	}
	return n;
}
int LL__prevN(LL* myLL, int n)
{
	for (; n > 0; --n) {
		if (!LL__prev(myLL)) {
			break;
		}
	}
	return n;
}

int LL__moveN(LL* myLL, int n)
{
	if (n > 0) {
		return LL__nextN(myLL, n);
	} else if (n < 0) {
		return LL__prevN(myLL, -n);
	} else {
		return 0;
	}
}

void LL__toHead(LL* myLL)
{
	while (LL__prev(myLL));
}
void LL__toTail(LL* myLL)
{
	while (LL__next(myLL));
}

/* ==================  			END  Move			  	 ================== */

/* ========================================================================	*
 * 									Manipulate								*
 * ======================================================================== */

#define LLinsert(myLL)	LL__insert(&(myLL))
void LL__insert(LL* myLL)
{

}

/* ==================  			END  Manipulate		  	 ================== */

/* ========================================================================	*
 * 									Tests									*
 * ======================================================================== */
#ifdef DEBUG
int main()
{
	LL intList = LLnew(int)(64, 32, 16, 8, 4, 2, 1);
	printf("length=%d\n", intList.length);
	printf("CURRINT=%d\n", LLread(int)(intList));
	LLprev(intList); printf("prev\n");
	printf("CURRINT=%d\n", LLread(int)(intList));

	printf("\n================================\n\n");

	LL doubleList = LLnew(double)(999.9, 888.8, 777.7, 666.6);
	printf("length=%d\n", doubleList.length);
	printf("> %g\n", LLread(double)(doubleList));

	printf("\n================================\n\n");

	LL ldList = LLnew(longdouble)(999.9, 888.8, 777.7, 666.6);
	printf("length=%d\n", ldList.length);
	printf("> %Lg\n", LLread(longdouble)(ldList));

}
#endif
/* ==================  			END  Tests				  ================== */
