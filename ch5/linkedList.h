#ifndef LINKEDLIST_H
#include "types.h"


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

/* ========================================================================	*
 * 								Initialization								*
 * ======================================================================== */
#ifndef LLnew
/*  Usage: 
 *  	LLnew(int, 1, 2, 3)
 *  	LLnew(sizeof(int), 1, 2, 3)
 *  	LLnew(4, 1, 2, 3) 
 *  are all equivalent */
#define LLnew(typeOrSize, ...)	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
#define newLinkedList(typeOrSize, ...)	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
#endif /* LLnew */

/* ========================================================================	*
 * 							Operations, manipulation						*
 * ======================================================================== */
#ifndef LLread
/* Usage: LLread(type)(myLL) */
#define LL__READLLCALLPASTER(type)	LL__read ## type ## LL
#define LLread(type)	LL__READLLCALLPASTER(type)
#endif /* LLread */

/*  Changes the link the passed LinkedList points to */
#define LLnext(myLL)	LL__nextLink(&(LL))
int LL__nextLink(LL* myLL);
#define LLprev(myLL)	LL__prevLink(&(LL))
int LL__prevLink(LL* myLL);


#endif /* LINKEDLIST_H */
