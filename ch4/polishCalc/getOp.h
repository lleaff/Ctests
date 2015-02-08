//Returns the type of the character, whether it is a number or an operator, 
// and skips whitespaces and misc characters.
#ifndef GETOP_H
#define GETOP_H

#define NUMBER -6	//Return code to indicate a digit
#define COMMAND -7 	//Return code to indicate a command
#define VARIABLE -8	//Return code to indicate a variable
#define ASSIGNMENT -9 //Return code to indicate a variable assignment
#define SKIP ' '	//Return code to indicate to skip the char

//Math operations return codes
#define NOCMD 'o'
#define REGCMD 'r'
#define SIN 's'
#define EXP 'e'
#define POW 'p'

char getOp(char input);
int pullOC(void); //Returns the number of operands before an operator

#endif /* GETOP_H */
