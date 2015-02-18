#include <stdio.h>

int main()
{
	printf("%14s = %-2i b\n", "word size", sizeof(float) * 8); //Word size is same as float size, usually
	printf("%14s = %-2i B\n", "sizeof(float)", sizeof(float));
	printf("%14s = %-2i B\n", "sizeof(double)", sizeof(double));
	printf("%14s = %-2i B\n", "sizeof(long)", sizeof(long));
	printf("%14s = %-2i B\n", "sizeof(char)", sizeof(char));
	return 0;
}
