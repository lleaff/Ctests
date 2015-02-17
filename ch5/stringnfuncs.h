#ifndef STRINGNFUNCS_H
#define STRINGNFUNCS_H
/* Include string.h before macros to avoid conflicts if another included file needs string.h */
#include <string.h>

int String__strncat(void *str1, void *str2, int n);
#define strncat(str1, str2, n)	String__strncat(&(str1), &(str2), n)

int String__strncpy(void *str1, void *str2, int n);
#define strncpy(str1, str2, n)	String__strncpy(&(str1), &(str2), n)

#endif /* STRINGNFUNCS_H */
