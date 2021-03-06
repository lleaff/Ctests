#include <stdio.h>
#include <stddef.h>

int main()
{
	printf("\n-----------------------		Unorganized		-----------------------\n\n");

	typedef struct house {
		double horse;
		int cat;
		char rabbit;
		float pig;
		char rabbit2;
	} house;

	struct house myHouse;
	printf("\
double horse;\n\
int cat;\n\
char rabbit;\n\
float pig;\n\
char rabbit2;\n\
\n");
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myHouse.horse)",	(int)sizeof(myHouse.horse),
			"offsetof(house, horse)",	(int)offsetof(house, horse));
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myHouse.rabbit)",	(int)sizeof(myHouse.rabbit),
			"offsetof(house, rabbit)",	(int)offsetof(house, rabbit));
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myHouse.rabbit2)",	(int)sizeof(myHouse.rabbit2),
			"offsetof(house, rabbit2)",	(int)offsetof(house, rabbit2));
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myHouse.cat)",		(int)sizeof(myHouse.cat),	
			"offsetof(house, cat)",		(int)offsetof(house, cat));
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myHouse.pig)",		(int)sizeof(myHouse.pig),	
			"offsetof(house, pig)",		(int)offsetof(house, pig));
	printf("\nsizeof(myHouse) = %i\n", (int)sizeof(myHouse));

	printf("\n-----------------------		Organized		-----------------------\n\n");

	typedef struct cabin {
		int cat;
		char rabbits[8];
		float pig;
		char mouse1;
		char mouse2;
		char mouse3;
		double horse;
		char mouse4;
		char mouse5;
		char mouse6;
		char mouse7;
		char mouse8;
	} cabin;

	struct cabin myCabin;

	printf("\
int cat;\n\
char rabbit;\n\
char rabbit2;\n\
float pig;\n\
double horse;\n\
\n");
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myCabin.horse)",	(int)sizeof(myCabin.horse),
			"offsetof(cabin, horse)",	(int)offsetof(cabin, horse));
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myCabin.rabbit)",	(int)sizeof(myCabin.rabbits),
			"offsetof(cabin, rabbit)",	(int)offsetof(cabin, rabbits));
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myCabin.cat)",		(int)sizeof(myCabin.cat),	
			"offsetof(cabin, cat)",		(int)offsetof(cabin, cat));
	printf("%-22s = %-2i  %-23s = %-2i\n", "sizeof(myCabin.pig)",		(int)sizeof(myCabin.pig),	
			"offsetof(cabin, pig)",		(int)offsetof(cabin, pig));
	printf("\nsizeof(myCabin) = %i\n", (int)sizeof(myCabin));

	return 0;
}
