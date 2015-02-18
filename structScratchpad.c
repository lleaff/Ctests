#include <stdio.h>
#include <stddef.h>

int main()
{
	typedef struct house {
		double horse;
		char rabbit;
		int cat;
		float pig;
	} house;

	struct house cabin;

	printf("%-20s = %-2i  %-23s = %-2i\n", "sizeof(cabin.horse)",	(int)sizeof(cabin.horse),
			"offsetof(house, horse)",	(int)offsetof(house, horse));
	printf("%-20s = %-2i  %-23s = %-2i\n", "sizeof(cabin.rabbit)",	(int)sizeof(cabin.rabbit),
			"offsetof(house, rabbit)",	(int)offsetof(house, rabbit));
	printf("%-20s = %-2i  %-23s = %-2i\n", "sizeof(cabin.cat)",		(int)sizeof(cabin.cat),	
			"offsetof(house, cat)",		(int)offsetof(house, cat));
	printf("%-20s = %-2i  %-23s = %-2i\n", "sizeof(cabin.pig)",		(int)sizeof(cabin.pig),	
			"offsetof(house, pig)",		(int)offsetof(house, pig));

	return 0;
}
