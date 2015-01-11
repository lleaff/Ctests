#include <stdio.h>

int fahrToCels(int fahr);

#ifndef MAIN
#define MAIN
int main () {
	double fahr, cels;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("%3s%6s\n", "°F", "°C");
	while(fahr <= upper) {
		cels = fahrToCels(fahr);
		printf ("%3.0f%6.1f\n", fahr, cels);
		fahr += step;
	}
}
#endif 

int fahrToCels(int fahr) {
	return 5 * ( fahr - 32) / 9;
}
