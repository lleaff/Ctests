#include <stdio.h>

int main () {
	double fahr, cels;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("%3s%6s\n", "°F", "°C");
	while(fahr <= upper) {
		cels = 5 * ( fahr - 32 ) / 9;
		printf ("%3.0f%6.1f\n", fahr, cels);
		fahr += step;
	}
}
