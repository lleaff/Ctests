// Contains the stack of double numbers and provides the push
//and pull functions to interact with said stack

#ifndef VALSTACK_H
#define VALSTACK_H
//Numbers
void push(double value);
double pull(void);
double readTopValue(void);
//Variables
void pushVar(char myChar);
void setVar(double value);
#endif /* VALSTACK_H */
