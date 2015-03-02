#include "../../debug.h"

#include "sort.h"
#include <limits.h>

#include <string.h> //memcopy()

#define SWAP(a, b, size)	do{ char tmp__swap__macro__mem[size];\
	memcpy(tmp__swap__macro__mem, &(a), size); \
	memcpy(&(a), &(b), size); \
	memcpy(&(b), tmp__swap__macro__mem, size); \
	}while(0)

int compareInt(void* val1, void* val2)
{
	if (*(int*)val1 > *(int*)val2) {
		return 1;
	} else if (*(int*)val1 < *(int*)val2) {
		return -1;
	} else {
		return 0;
	}
}

static inline void initLogArray(int, int*);
//Sort an array of values and log the values new indexes in an additional array
void SORT__sortAndLog(
		int arrSize, void* array, int* log, int comp(void*, void*), int reversed, void* extreme, int typeSize )
{
	reversed = reversed ? -1 : 1;
	initLogArray(arrSize, log);
	DEBUGP("log: "); PRINTINTARR(11, log, ", "); DEBUGP("\n");
	//Simple algorithm: swap the smallest value with the current one
	char minVal[arrSize]; //Memory for generic min value holder
	memcpy(minVal, extreme, typeSize);
	int maxI = -1;
	int i, j;
	for (i = 0; i < arrSize; ++i) {
		for (j = i; j < arrSize; ++j) {
			if (comp(array + j*typeSize, &minVal) * reversed < 0) {
				DEBUGP("\t%11d < %-11d\n", *(int*)(array + j*typeSize), *(int*)minVal)
				memcpy(minVal, array + j*typeSize, typeSize);
				maxI = j;
			}
		}
		if (maxI != -1) {
			DEBUGP("LETS SWAP  (%d <-> %d)\n", *(int*)(array + i*typeSize), *(int*)(array + maxI*typeSize))
			SWAP(*(char*)(array + i*typeSize), *(char*)(array + maxI*typeSize), sizeof(int));
			SWAP(log[maxI], log[i], sizeof(int));
			maxI = -1; //Reset minVal index
			memcpy(minVal, extreme, typeSize);
		}
	}
}

inline void sortAndLogInt(int arrSize, int array[], int logArray[])
{
	int extreme = INT_MAX;
	SORT__sortAndLog(arrSize, array, logArray, &compareInt, 0, &extreme, sizeof(int));
}
inline void sortAndLogRInt(int arrSize, int array[], int logArray[])
{
	int extreme = INT_MIN;
	SORT__sortAndLog(arrSize, array, logArray, &compareInt, 1, &extreme, sizeof(int));
}

/* log[0] = 0, log[1] = 1, log[2] = 2, ... */
static inline void initLogArray(int arrSize, int* log)
{
	while (--arrSize >= 0) {
		*(log + arrSize) = arrSize;
	}
}

#ifdef DEBUG
int main()
{

	int testArrU[11] = { 888, 24, 694, 1234, 111, -543, 435, 99999, 0 , 132, 0 };
	int testArrLog[11];
	PRINTINTARR(11, testArrU, ", "); printf("\n");
	sortAndLogRInt(11, testArrU, testArrLog);
	printf("sort...\n\n");
	PRINTINTARR(11, testArrU, ", "); printf("\n");
	PRINTINTARR(11, testArrLog, ", "); printf("\n");

}
#endif /* DEBUG */
