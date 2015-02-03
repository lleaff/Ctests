#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

#ifndef BUFFER_H
#define BUFFER_H

//---Numbers
BOOL doubleIsNAN(double num);
void storeNum(char digit);
double pullNum(void);

//---Commands
#define MAXCOMMANDSIZE 50
void storeCommand(char myChar);
//Returns the index of the given string which matches the stored one, otherwise returns -1
int compareCommand();
void resetCommand();

#endif /* BUFFER_H */
