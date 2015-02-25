#define DEBUG
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

/* ========================================================================	*
 * 								The structs									*
 * ======================================================================== */

#ifndef LL
#define LL LL
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
#endif /* LL */

/* =========================  END The structs	==========================	*/

/* ========================================================================	*
 * 								Initialization								*
 * ======================================================================== */
Link* LL__newLink(int size, void* elemmem, Link* prev);
static void resolveTypeAndSizeFromString(char* myString, int myStringValue, TYPE* type, int* size);
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap);

#define LASTARGID_LLD 242319717654231400
static const long long LastArgId_LLD = LASTARGID_LLD;

#ifndef LLnew
#define LLnew(typeOrSize, ...)	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
#define newLinkedList(typeOrSize, ...)	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
#endif /* LLnew */

LL LL__LLnew(char* typeOrSize, int typeOrSizeValue, ...)
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
	myLinkedList.length = length;
	return myLinkedList;
}

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

/*  Returns 0 if there is no argument left */
static int initElemmem(const TYPE* type, void* elemmem, va_list* ap)
{
	if (**(long long**)ap == LastArgId_LLD) {
		va_end(*ap);
		DEBUGP("------LastArgReached------\n")
		return 0; //Last argument
	}
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

/* ==================  			END  Read				 ================== */

/* ========================================================================	*
 * 									Move									*
 * ======================================================================== */

#define LLnext(myLL)	LL__nextLink(&(LL))
int LL__nextLink(LL* myLL)
{
	if (myLL->curr->next != NULL) {
		myLL->curr = myLL->curr->next;
		return 1; //Success
	} else {
		return 0; //Last link
	}
}
#define LLprev(myLL)	LL__prevLink(&(LL))
int LL__prevLink(LL* myLL)
{
	if (myLL->curr->prev != NULL) {
		myLL->curr = myLL->curr->prev;
		return 1; //Success
	} else {
		return 0; //First link
	}
}


#define LLnextn(myLL, n)	LL__nextNLinks(&(LL), n)
int LL__nextNLinks(LL* myLL, int n)
{
	for (; n > 0; --n) {
		if (!LL__nextLink(myLL)) {
			break;
		}
	}
	return n;
}
#define LLprevn(myLL, n)	LL__prevNLinks(&(LL), n)
int LL__prevNLinks(LL* myLL, int n)
{
	for (; n > 0; --n) {
		if (!LL__prevLink(myLL)) {
			break;
		}
	}
	return n;
}

#define LLmove(myLL, n)	LL__moveN(&(LL), n)
int LL__moveN(LL* myLL, int n)
{
	if (n > 0) {
		return LL__nextNLinks(myLL, n);
	} else if (n < 0) {
		return LL__prevNLinks(myLL, -n);
	} else {
		return 0;
	}
}

/* ==================  			END  Move			  	 ================== */

/* ========================================================================	*
 * 									Tests									*
 * ======================================================================== */
#ifdef DEBUG
int main()
{
	LL intList = LLnew(sizeof(int), 64, 32, 16, 8, 4, 2, 1);
	printf("length=%d\n", intList.length);
	DEBUGP("&&& intList.curr=%p\n", intList.curr)
	printf("intList.curr->elem=%d\n", *(int*)((intList.curr)->elem));

	Link currLink = *(intList.curr);
	printf("Link currLink = *(intList.curr);\n");
	printf("currLink.elem=%d\n", *(int*)currLink.elem);

	*(int*)((intList.curr)->elem) = 555;
	printf(">>>>*(int*)(intList.curr)->elem = 555;\n");

	printf("((intList.curr->prev))->elem=%d\n", *(int*)(intList.curr->prev->elem));
	printf("((intList.curr->next))->elem=%d\n", intList.curr->next == NULL ? 666 : *(int*)(intList.curr->next->elem));

	printf("\nCURRINT: %d\n", LLread(int)(intList));
}
#endif
/* ==================  			END  Tests				  ================== */
