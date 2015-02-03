#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

//Does the actual operations and get values from the stack
// using the provided push and pop functions.
#ifndef CALC_H
#define CALC_H
double calc(char input[], BOOL *shouldPrintValue);
#endif /* CALC_H */
