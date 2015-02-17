#define DEBUG
#include "stringnfuncs.h"
#include "../debug.h"

#include "stringType.h"
#include <stdio.h>

#define MAX(val1, val2)		((val1 > val2) ? val1 : val2)
#define MIN(val1, val2)		((val1 < val2) ? val1 : val2)

int String__strncat(void *str1, void *str2, int n)
{
	int l1 = strlen(*(void **)str1), l2 = strlen(*(void **)str2);
	char *string1Chars = getStringChars(str1);
	char *string2Chars = getStringChars(str2);
	int returnVal = 0;
	int newLength = l1 + MIN(n, l2);
	if (isStringType((void **)str1)) {
		String string1 = *(String *)str1;
		if (!((string1.LengthLimit <= l1 + n) && 
					(string1.LengthLimit <= l1 + l2))) {
			changeStringLength(string1, l1 + n);
			/*  Return the number of extra characters */
			returnVal = n - (MAX(string1.LengthLimit, strlen(str2)));
		}
		string1.Length = newLength;
		string1.Chars[newLength] = '\0';
	} else {
		if (l1 <= l1 + MIN(l2, n)) {
		} else {
			fprintf(stderr, "ERROR: stringnfuncs.c:String__strncat: destination string too short\n");
			returnVal = l1 - MIN(l2, n); //Failure, result < 0
			return returnVal;
		}
	}
	memcpy(string1Chars + l1, string2Chars, (newLength - l1) * sizeof(char));
	return returnVal;
}

int String__strncpy(void *str1, void *str2, int n)
{
	int l1 = strlen(*(void **)str1), l2 = strlen(*(void **)str2);
	char *string1Chars = getStringChars(str1);
	char *string2Chars = getStringChars(str2);
	int returnVal = 0;
	if (isStringType((void **)str1)) {
		String string1 = *(String *)str1;
		if (!(string1.LengthLimit >= MIN(n, l2))) {
			changeStringLength(string1, MIN(n, l2));
			/*  Return the number of extra characters */
			returnVal = MAX(n, l2);
		}
		int newLength = MIN(n, l2);
		string1.Length = newLength;
		string1Chars[newLength] = '\0';
	} else {
		if (l1 <= l1 + MIN(l2, n)) {
		} else {
			fprintf(stderr, "ERROR: stringnfuncs.c:String__strncpy: destination string too short\n");
			returnVal = l1 - MIN(l2, n); //Failure, result < 0
			return returnVal;
		}
	}
	memcpy(string1Chars, string2Chars, (MIN(n, l2)) * sizeof(char));
	return returnVal;
}


#ifdef DEBUG
#include <stdlib.h>	//For testing with rand()
#include <time.h>	//For seeding rand() with srand(time())
int randInt(int lo, int up)
{
	rand(); rand(); rand(); rand(); //Skip some rand()
	return ((rand() * (up - lo)) / RAND_MAX) + lo + 0.5;
}

int main()
{
	String teststr1 = newString(50, "Hello...");
	String teststr2 = newString(50, "Goodbye Mister");
	srand((int)time(NULL));
	int n;
	printf("\n");
	printf("str1: %s\nstr2: %s\n", teststr1.Chars, teststr2.Chars);
	n = randInt(0, strlen(teststr2));
	printf("--- Copy the first %d characters from str2 at the end of str1...\n", n);
	strncat(teststr1, teststr2, n);
	printf("str1: %s\nstr2: %s\n", teststr1.Chars, teststr2.Chars);
	printf("\n");
	n = randInt(0, strlen(teststr2));
	String teststr3 = newString(50, "Hello...");
	printf("str3: %s\nstr2: %s\n", teststr3.Chars, teststr2.Chars);
	printf("--- Copy the first %d characters from str2 on str3...\n", n);
	strncpy(teststr3, teststr2, n);
	printf("str3: %s\nstr2: %s\n", teststr3.Chars, teststr2.Chars);


	return 0;
}

#endif /*  DEBUG */
