#ifndef DEBUG_H
#define DEBUG_H
//Put "#define DEBUG" at the top of your file to enable the functions
#ifdef DEBUG
#include <stdio.h>
#include <ctype.h>
#define DEBUGPRINT(...)		do {fprintf(stderr, __VA_ARGS__);}while(0);
#define DEBUGP(...)			DEBUGPRINT(__VA_ARGS__)
#define DEBUGSTATEMENT(...)	__VA_ARGS__
#define DEBUGS(...)	DEBUGSTATEMENT(__VA_ARGS__)

#define PUTCHARLIT(myChar)	do{switch (myChar) {\
case '\t':printf("\\t");break;\
case '\n':printf("\\n");break;\
case '\0':printf("\\0");break;\
case ' ':printf("_space_");break;\
default:putchar(myChar);break;}\
}while(0);

#define TOLOWER(myString)	DEBUG__TOLOWER(myString)
char* DEBUG__TOLOWER(char* myString)
{ int i; for(i=0;myString[i]!='\0';++i){myString[i]=tolower(myString[i]);} return myString; }

#define TOUPPER(myString)	DEBUG__TOUPPER(myString)
char* DEBUG__TOUPPER(char* myString)
{ int i; for(i=0;myString[i]!='\0';++i){myString[i]=toupper(myString[i]);} return myString; }

#else
#define DEBUGPRINT(...)
#define DEBUGP(...)
#define DEBUGSTATEMENT(...)
#define DEBUGS(...)
#define PUTCHARLIT(myChar)
#define TOLOWER(myString)
#define TOUPPER(myString)
#endif /* DEBUG */

#endif /* DEBUG_H */
