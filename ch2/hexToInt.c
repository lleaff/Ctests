#include <stdio.h>
#include <math.h>

#define MAXLINESIZE 1000

int hexToInt(char hex[]);

int main()
{
	char testHex[MAXLINESIZE];
	printf("Enter an hexadecimal number to converter to base 10\n> ");
	scanf("%s", testHex);
	printf("> %d", hexToInt(testHex));
	return 0;
}

int hexDigitToDecimalInt(char hex)
{
	int decimal;
	if (hex >= '0' && hex <= '9') {
		decimal = hex - '0';
	} else if (hex >= 'a' && hex <= 'f') {
		decimal = 10 + hex - 'a';
	} else if (hex >= 'A' && hex <= 'F') {
		decimal = 10 + hex - 'A';
	} else {
		decimal = -1; //ERROR hex isn't between 0 and 15
	}
	return decimal;
}

int hexToInt(char hex[])
{
	int integer = 0;
	int start;
	if (hex[0] == 0 && (hex[1] == 'x' || hex[1] == 'X')) {
		start = 2; // in case string begins by 0x/0X
	} else {
		start = 0;
	}
	int i;
	for (i = start; hex[i] != '\0'; i++) { // go to end of string
	}
	i--; //correct
	int j;
	for (j = 0; i >= start; i--, j++) {
		integer += hexDigitToDecimalInt(hex[i]) * (int)pow(16, j);
#ifdef DEBUG
		printf("pow(16, %d)=%d\t%c\tdigit=%d\t\tint=%d\n", j, (int)pow(16, j), hex[i], hexDigitToDecimalInt(hex[i]), integer);//DEBUG
#endif
	}
	return integer;
}
