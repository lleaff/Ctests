#ifndef DEBUG_H
#define DEBUG_H
//Put "#define DEBUG" at the top of your file to enable the functions
#include <stdio.h>
#ifdef DEBUG
#define DEBUGPRINT(...)		fprintf(stderr, __VA_ARGS__)
#define DEBUGP(...)			DEBUGPRINT(__VA_ARGS__)
#define DEBUGSTATEMENT(...)	__VA_ARGS__
#else
#define DEBUGPRINT(...)
#define DEBUGP(...)
#define DEBUGSTATEMENT(...)
#endif /* DEBUG */
#endif /* DEBUG_H */
