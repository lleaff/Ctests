#ifndef BUFFER_H
#define BUFFER_H
typedef enum { FALSE, TRUE } BOOL;
BOOL doubleIsNAN(double num);
void storeNum(char digit);
double pullNum(void);

#define EMPTY -2
void pushChar(char character);
char pullChar(void);
#endif /* BUFFER_H */
