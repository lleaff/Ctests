#ifndef LINKEDLIST_H
#include "types.h"

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

/* ========================================================================	*
 * 								The structs									*
 * ======================================================================== */
#define LinkedList LL //Verbose form

typedef struct LL {
	struct LL__Link* curr;
	int length;
} LL;

typedef struct LL__Link {
	struct LL__Link* prev;
	struct LL__Link* next;
	TYPE type;
	char elem[];
} LL__Link;

/* ========================================================================	*
 * 								Initialization								*
 * ======================================================================== */
#ifndef LL__CallLLnew
/* Usage: LLnew(type)(myLL) */
#define LL__CallLLnew(typeOrSize, ...)	\
	LL__LLnew(#typeOrSize, (int)typeOrSize, __VA_ARGS__, LastArgId_LLD)
LL LL__LLnew(char* typeOrSize, int typeOrSizeValue, ...);

#define charLLnew(...)			LL__CallLLnew(CHAR, __VA_ARGS__)
#define shortLLnew(...)			LL__CallLLnew(SHORT, __VA_ARGS__)
#define intLLnew(...) 			LL__CallLLnew(INT, __VA_ARGS__)
#define longLLnew(...) 			LL__CallLLnew(LONG, __VA_ARGS__)
#define floatLLnew(...)			LL__CallLLnew(FLOAT, __VA_ARGS__)
#define doubleLLnew(...)		LL__CallLLnew(DOUBLE, __VA_ARGS__)
#define longdoubleLLnew(...)	LL__CallLLnew(LONGDOUBLE, __VA_ARGS__)

#define LL__NEWLLCALLPASTER(type)	type ## LLnew
#define	LLnew(type)	LL__NEWLLCALLPASTER(type)
#endif /* LL__CallLLnew */

/* ========================================================================	*
 * 									Read									*
 * ======================================================================== */
#ifndef LLread
/* Usage: LLread(type)(myLL) */
#define LL__READLLCALLPASTER(type)	LL__read ## type ## LL
#define LLread(type)	LL__READLLCALLPASTER(type)
#endif /* LLread */
char 		LL__readcharLL		(LL myLL);
short 		LL__readshortLL		(LL myLL);
int 		LL__readintLL		(LL myLL);
long 		LL__readlongLL		(LL myLL);
float 		LL__readfloatLL		(LL myLL);
double 		LL__readdoubleLL	(LL myLL);
long double LL__readlongdoubleLL(LL myLL);

#define LLisHead(myLL)	LL__isHead(&(myLL))
BOOL LL__isHead(LL* myLL);
#define LLisTail(myLL)	LL__isTail(&(myLL))
BOOL LL__isTail(LL* myLL);


#define getLink(myLL)		LL__getLink(&(myLL))
LL__Link LL__getLink(LL* myLL);
#define nextLink(myLL)		LL__nextLink(&(myLL))
LL__Link LL__nextLink(LL* myLL);
#define prevLink(myLL)		LL__prevLink(&(myLL))
LL__Link LL__prevLink(LL* myLL);
#define nextNLinks(myLL, n)	LL__nextNLinks(&(myLL), n)
LL__Link LL__nextNLinks(LL* myLL, int n);
#define prevNLinks(myLL, n)	LL__prevNLinks(&(myLL), n)
LL__Link LL__prevNLinks(LL* myLL, int n);
#define readNLink(myLL, n)	LL__readN(&(myLL), n)
LL__Link LL__readN(LL* myLL, int n);

/* ========================================================================	*
 * 									Move									*
 * ======================================================================== */
/*  Changes the link the passed LinkedList points to,
 *   returns 0 if the current link is tail or head,
 *   returns 1 if the new link is in the middle */
#define LLnext(myLL)	LL__next(&(myLL))
int LL__next(LL* myLL);
#define LLprev(myLL)	LL__prev(&(myLL))
int LL__prev(LL* myLL);

/*  Returns the number of moves not performed due to reaching tail or head  */
#define LLnextn(myLL, n)	LL__nextN(&(myLL), n)
int LL__nextN(LL* myLL, int n);
#define LLprevn(myLL, n)	LL__prevN(&(myLL), n)
int LL__prevN(LL* myLL, int n);
/*  Moves to the n previous links if n < 0, to the n next links if n > 0,
 *   returns the number of moves not performed due to reaching tail or head  */
#define LLmove(myLL, n)	LL__moveN(&(myLL), n)
int LL__moveN(LL* myLL, int n);

#define LLtoHead(myLL)	LL__toHead(&(myLL))
void LL__toHead(LL* myLL);
#define LLtoTail(myLL)	LL__toTail(&(myLL))
void LL__toTail(LL* myLL);

/* ========================================================================	*
 * 									Manipulate								*
 * ======================================================================== */
#define LLinsert(myLL)	LL__insert(&(myLL))
void LL__insert(LL* myLL);
#define LLappend(myLL)	LL__append(&(myLL))
void LL__append(LL* myLL);

#endif /* LINKEDLIST_H */
