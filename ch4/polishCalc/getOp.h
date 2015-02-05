//Returns the type of the character, whether it is a number or an operator, 
// and skips whitespaces and misc characters.
#ifndef GETOP_H
#define GETOP_H

#define NUMBER -6	//Return code to indicate a digit
#define COMMAND -5 	//Return code to indicate a command
#define SKIP ' '	//Return code to indicate to skip the char

//Math operations return codes
#define NOCMD 'o'
#define REGCMD 'r'
#define SIN 's'
#define EXP 'e'
#define POW 'p'

char getOp(char input);

#endif /* GETOP_H */
