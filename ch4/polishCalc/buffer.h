#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

#ifndef BUFFER_H
#define BUFFER_H
BOOL doubleIsNAN(double num);
void storeNum(char digit);
double pullNum(void);
void storeCommand(char myChar);
//Returns the index of the given string which matches the stored one, otherwise returns -1
int compareCommand(int commandC, char *commands[]);
#endif /* BUFFER_H */
