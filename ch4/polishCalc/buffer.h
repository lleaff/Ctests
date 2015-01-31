#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

#ifndef BUFFER_H
#define BUFFER_H
BOOL doubleIsNAN(double num);
void storeNum(char digit);
double pullNum(void);

#define EMPTY -2
void pushChar(char character);
char pullChar(void);
#endif /* BUFFER_H */
