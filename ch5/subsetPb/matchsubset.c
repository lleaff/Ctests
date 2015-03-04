#define DEBUG
#include "../../debug.h"

#include "sort.h"

int findSubsetSum(int arrSize, int values[], int subset[], int target)
{
	int sortLog[arrSize];
	int i, j;
	int found = 0;
	for (i = 0; i < arrSize && i < ; ++i) {

	}

	return found;
}

#ifdef DEBUG
#include <stdio.h>

int main()
{
#define SUBSET__TESTVALUESC 26
	int values[SUBSET__TESTVALUESC] = { 18897109, 12828837, 9461105, 6371773, 5965343, 5946800, 5582170, 5564635, 5268860, 4552402, 4335391, 4296250, 4224851, 4192887, 3439809, 3279833, 3095313, 2812896, 2783243, 2710489, 2543482, 2356285, 2226009, 2149127, 2142508, 2134411 };
	int subset[SUBSET__TESTVALUESC];
	int target = 100000000;

	if (findSubsetSum(SUBSET__TESTVALUESC, values, subset, target)) {
		int i, x = 0;
		for (i = 0; i < SUBSET__TESTVALUESC; i++) {
			if (subset[i]) {
				x = 1;
				printf("%s%d ", x ? "+ " : "", values[i]);
			}
			printf("= %d\n", target);
		}
	} else {
		printf("No sum of values subset add to %d\n", target);
	}
}

#endif /* DEBUG */
