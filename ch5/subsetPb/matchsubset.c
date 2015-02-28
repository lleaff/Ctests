#define DEBUG
#include "../../debug.h"

//#include "../types.h"
//
//
//int add(void* num1, void* num2)
//{
//	return (int)num1 + (int)num2;
//}
//
/////* Completely generic subset search function */
//void SUBSET__findSubset(
//		TYPE type, 
//		void* (*operation)(void* result, void*, void*), /* The function applied to the array values to form the subsets */
//		int (*comparison)(void* myMatch, void* myValue), /* The function used for comparison */
//		int comparisonResult, /* Expected result from the comparison function: 0 for match, 1 for >, -1 for < */
//		void* match /* Searched value */,
//		void* data /* Array of values to search subset in */,
//		char* subset /* Array symetrical to data, 1 = in subset, 0 = not in subset */)
//{
//
//}

//Scratch that let's just do a simple one just to solve my problem first


int findAddSubset(int size, int values[], int subset[], int match)
{

}

#ifdef DEBUG
#include <stdio.h>

int main()
{
#define SUBSET__TESTVALUESC 26
	int populations[SUBSET__TESTVALUESC] = { 18897109, 12828837, 9461105, 6371773, 5965343, 5946800, 5582170, 5564635, 5268860, 4552402, 4335391, 4296250, 4224851, 4192887, 3439809, 3279833, 3095313, 2812896, 2783243, 2710489, 2543482, 2356285, 2226009, 2149127, 2142508, 2134411 };
	int subset[SUBSET__TESTVALUESC];
	int target = 100000000;

	if (findAddSubset(SUBSET__TESTVALUESC, populations, subset, target)) {
		int i, x = 0;
		for (i = 0; i < SUBSET__TESTVALUESC; i++) {
			if (subset[i]) {
				x = 1;
				printf("%s%d ", x ? "+ " : "", populations[i]);
			}
			printf("= %d\n", target);
		}
	} else {
		printf("No sum of values subset add to %d\n", target);
	}
}

#endif /* DEBUG */
