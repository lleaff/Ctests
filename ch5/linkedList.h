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
#define LLnew(typeOrSize, ...)	\
	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
#define newLinkedList(typeOrSize, ...)	\
	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
#endif /* LLnew */

/* ========================================================================	*
 * 									Read									*
 * ======================================================================== */
#ifndef LLread
/* Usage: LLread(type)(myLL) */
#define LL__READLLCALLPASTER(type)	LL__read ## type ## LL
#define LLread(type)	LL__READLLCALLPASTER(type)
#endif /* LLread */

/* ========================================================================	*
 * 									Move									*
 * ======================================================================== */
/*  Changes the link the passed LinkedList points to,
 *   returns 0 if the current link is tail or head,
 *   returns 1 if the new link is in the middle */
#define LLnext(myLL)	LL__nextLink(&(LL))
int LL__nextLink(LL* myLL);
#define LLprev(myLL)	LL__prevLink(&(LL))
int LL__prevLink(LL* myLL);

/*  Returns the number of moves not performed due to reaching tail or head  */
#define LLnextn(myLL, n)	LL__nextNLinks(&(LL), n)
int LL__nextNLinks(LL* myLL, int n);
#define LLprevn(myLL, n)	LL__prevNLinks(&(LL), n)
int LL__prevNLinks(LL* myLL, int n);
#define LLmove(myLL, n)	LL__moveN(&(LL), n)
int LL__moveN(LL* myLL, int n);

#endif /* LINKEDLIST_H */
