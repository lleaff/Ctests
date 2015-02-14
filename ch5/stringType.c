#include "stringType.h"
#include <stdlib.h>
#include <string.h>

#define MIN(val1, val2)	((val1 < val2 ? val1 : val2))

#define STRINGTYPEID 16.5541e59
const double __StringTypeID_ref = STRINGTYPEID;

String newString(int length, char *cStyleString)
{
	String myString;
	if (cStyleString == NULL) {
		myString.Chars = malloc((sizeof(char) * length) + 1);
		myString.Length = myString.LengthLimit = length;
	} else {
		CopyString(myString, cStyleString);
		int i;
		for (i = 0; cStyleString[i] != '\0'; i++)
			;
		myString.Length = i;
		myString.LengthLimit = length;
	}
	myString.stringTypeID = __StringTypeID_ref;
	return myString;
}

int isStringType(void *ptr)
{
	return (*(double *)ptr == __StringTypeID_ref);
}

int strlen__flexible(void *ptr)
{
	if (isStringType(ptr)) { //Is "String" type
		return ((String*)ptr)->Length;
	} else { //Is C-style string
		int i;
		for (i = 0; *(char *)(ptr + (i * sizeof(char))) != '\0'; i++)
			;
		return i;
	}
}

//Returns 0 if both strings are String types, 1 if the origin string is C-type string
int CopyString(String destination, void *otherString)
{
	if (isStringType(otherString)) {
		memcpy(destination.Chars, (*(String *)otherString)->Chars, destination.Length * sizeof(char));
		return 0;
	} else {
		strcpy(destination.Chars, (char *)otherString);
		return 1;
	}
}

//Returns 0 if the two Strings perfectly match,
// -1 if the string partially match but have different lengths properties,
// index of first non-matching characters otherwise.
int compareStrings(String str1, String str2)
{
	int minLength = MIN(str1.Length, str2.Length);
	int i;
	for (i = 0; i < minLength;i++) {
		if (str1.Chars[i] == '\0') {
			if (str2.Chars[i] == '\0') {
				return 0; //Perfect match
			} else {
				return i; //Don't match
			}
		} else if (str2.Chars[i] == '\0') {
			return i; //Don't match
		} else if (str1.Chars[i] != str2.Chars[i]) {
			return i; //Don't match
		}
	}
	return 0 - (str1.Length != str2.Length);
}
