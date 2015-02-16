#include "stringType.h"
#include <stdio.h>

#define MAX(val1, val2)		((val1 > val2) ? val1 : val2)
#define MIN(val1, val2)		((val1 < val2) ? val1 : val2)

int String__strncat(void *str1, void *str2, int n)
{
	int l1 = strlen(str1), l2 = strlen(str2);
	char *string2Chars = (isStringType(str2)) ? (((String *)str2)->Chars) : str2;
	int returnVal = 0;
	if (isStringType(str1)) {
		String string1 = *(String *)str1;
		if (!((string1.LengthLimit <= l1 + n) && 
					(string1.LengthLimit <= l1 + l2))) {
			changeStringLength(string1, l1 + n);
			/*  Return the number of extra characters */
			returnVal = n - (MAX(string1.LengthLimit, strlen(str2)));
		}
		int newLength = l1 + MIN(n, l2);
		memcpy(string1.Chars + l1, string2Chars, newLength * sizeof(char));
		string1.Length = newLength;
		string1.Chars[newLength] = '\0';
	} else {
		if (l1 <= l1 + MIN(l2, n)) {
			strcpy(str1 + l1, string2Chars);
		} else {
			fprintf(stderr, "ERROR: stringnfuncs.c:String__strncat: destination string too short\n");
			returnVal = l1 - MIN(l2, n); //Failure, result < 0
		}
	}
	return returnVal;
}

int main()
{
	String teststr1 = newString(50, "Hello...");
	String teststr2 = newString(50, "Goodbye");
	
	printf("str1: %s\nstr2: %s\n", teststr1.Chars, teststr2.Chars);
	String__strncat(&teststr1, &teststr2, 4);
	printf("str1: %s\nstr2: %s\n", teststr1.Chars, teststr2.Chars);

	return 0;
}
