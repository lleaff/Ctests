#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <stdlib.h>
#include <time.h>

//Return index of value corresponding to searchedValue if found or -1 if not found
int searchInIntArr(int arrayLength, int array[], int searchedValue);

//Generates an array of given length filled with random integer values contained between the specified bounds
void randomArray(int length, int array[], int lowerLimit, int upperLimit);

#endif
