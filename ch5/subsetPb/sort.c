#define DEBUG
#include "sort.h"
#include <limits.h>

int compareInt(void* val1, void* val2)
{
	return *(int*)val1 - *(int*)val2;
}

//Sort an array of values and log the values new indexes in an additional array
void SORT__sortAndLog(int size, void* array, void* log, int comp(void*, void*), int reversed, void* extreme)
{
	//Naive algorithm
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = i + 1; j < size; ++j) {
			if (comp(array + i, extreme) > 0) {

			}
		}
	}
}

inline void sortAndLogInt(int size, int array[], int logArray[])
{
	int extreme = INT_MIN;
	SORT__sortAndLog(size, array, logArray, &compareInt, 0, &extreme);
}
inline void sortAndLogRInt(int size, int array[], int logArray[])
{
	int extreme = INT_MAX;
	SORT__sortAndLog(size, array, logArray, &compareInt, 0, &extreme);
}

#ifdef DEBUG
int main()
{

}
#endif /* DEBUG */
