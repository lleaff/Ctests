#ifndef DEBUG_H
#define DEBUG_H
//Put "#define DEBUG" at the top of your file to enable the functions
#include <stdio.h>
#ifdef DEBUG
#define DEBUGPRINT(...)		fprintf(stderr, __VA_ARGS__)
#define DEBUGP(...)			DEBUGPRINT(__VA_ARGS__)
#define DEBUGSTATEMENT(...)	__VA_ARGS__
#define DEBUGS(...)	DEBUGSTATEMENT(__VA_ARGS__)
#define PUTCHARLIT(myChar)	do {Debug__putcharLit(myChar)} while(0)
void Debug__putcharLit(char myChar);
#else
#define DEBUGPRINT(...)
#define DEBUGP(...)
#define DEBUGSTATEMENT(...)
#define DEBUGS(...)
#define PUTCHARLIT(myChar)
#endif /* DEBUG */

#endif /* DEBUG_H */
