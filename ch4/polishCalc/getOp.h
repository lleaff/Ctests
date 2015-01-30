//Returns the type of the character, whether it is a number or an operator, 
// and skips whitespaces and misc characters.
#ifndef GETOP_H
#define GETOP_H

#define NUMBER -6	//Return code to indicate a digit /* 6 random number */
#define SKIP ' '	//Return code to indicate to skip the char
char getOp(char input);

#endif /* GETOP_H */
