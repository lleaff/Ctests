#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

// Contains the stack of double numbers and provides the push
//and pull functions to interact with said stack
#ifndef VALSTACK_H
#define VALSTACK_H
//Numbers
void push(double value);
double pull(void);
double readTopValue(void);
//Variables
void setVar(char myChar);
void pushVar(double value);
double readVar(void);
BOOL isVarInit(void);
#endif /* VALSTACK_H */
