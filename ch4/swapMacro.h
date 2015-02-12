#ifndef SWAPMACRO_H
#define SWAPMACRO_H
#include <stdlib.h>
#include <string.h>

#define MAX(val1, val2) ((val1 >= val2 ? val1 : val2))
#define MIN(val1, val2) ((val1 <= val2 ? val1 : val2))

//dummy do{...} while(0) so a trailing ; doesn't change interpretation and
// variables names don't conflict
#define SWAP(type, val1, val2) \
	do{type tmp = val2;val2 = val1;val1 = tmp;}while(0)
#define SWAPARR(type, length, arr1, arr2) \
	do{const int memSize = sizeof(type) * length;\
	void *tmp = malloc(memSize);\
	memcpy(tmp, arr2, memSize); memcpy(arr2, arr1, memSize);\
	memcpy(arr1, tmp, memSize);\
	free(tmp);} while(0)
#define SWAPSTR(str1, l1, str2, l2)	\
	do{char tmp[MAX(l1, l2)];\
	int minl = MIN(l1, l2);\
	memmove(tmp, str2, l2 + 1);\
	memmove(str2, str1, minl);\
	str2[minl] = '\0';\
	memmove(str1, tmp, minl);\
	str1[minl] = '\0';}while(0)

#endif /* SWAPMACRO_H */
