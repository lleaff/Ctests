#include <stdio.h>

int main() {
	int victim = 15;
	int mark = 6;

	int *bullet = &mark;
	
	//wind
	bullet -= 1;
	printf("bullet -= 1\n");

	printf("victim=%d\tmark=%d\tbulletTarget=%d\tbulletTargetAddress=%p\n", victim, mark, *bullet, bullet);

	//wind
	bullet += 1;
	printf("bullet += 1\n");

	printf("victim=%d\tmark=%d\tbulletTarget=%d\tbulletTargetAddress=%p\n", victim, mark, *bullet, bullet);

	//wind
	bullet += 1;
	printf("bullet += 1\n");

	printf("victim=%d\tmark=%d\tbulletTarget=%d\tbulletTargetAddress=%p\n", victim, mark, *bullet, bullet);
}
