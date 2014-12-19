#include <stdio.h>

int main() {
	int victim = 15;
	printf("int victim = 15;\nvictimAddress =\t%p\n", &victim);
	int mark = 6;
	printf("int mark = 6;\nmarkAddress =\t%p\n", &mark);

	int *bullet = &mark;
	
	//wind
	bullet -= 1;
	printf("bullet -= 1\n");

	printf("victim=%d\tmark=%d\tbulletTarget=%d\tbulletTargetAddress = %p\n", victim, mark, *bullet, bullet);

	//wind
	bullet += 1;
	printf("bullet += 1\n");

	printf("victim=%d\tmark=%d\tbulletTarget=%d\t\tbulletTargetAddress = %p\n", victim, mark, *bullet, bullet);

	//wind
	bullet += 1;
	printf("bullet += 1\n");

	printf("victim=%d\tmark=%d\tbulletTarget=%d\t\tbulletTargetAddress = %p\n", victim, mark, *bullet, bullet);
}
