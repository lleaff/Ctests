#include <stdio.h>

int main() {
	double fahrenheit = 0;
	scanf("%lf", &fahrenheit);
	double celsius = ( 5.0 / 9.0 ) * ( fahrenheit - 32.0);
	printf("%.3f", celsius);
}
