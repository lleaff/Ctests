#include <stdio.h>

char lowerChar(char myChar)
{
	return (myChar >= 'A' && myChar <= 'Z') ? ('a' + (myChar - 'A')) : myChar;
}

int main()
{
	char testChar;
	char characters[] = "LOTS OF test CHARACTERS lkqj$^*:!mù;\"_(-";
	int i;
	for (i = 0; characters[i] != '\0'; i++) {
		testChar = characters[i];
		printf("%c", lowerChar(testChar));
	}

}
