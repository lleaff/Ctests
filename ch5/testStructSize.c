#include <stdio.h>
#include <stddef.h>

typedef struct Link {
	struct Link* prev;
	struct Link* next;
	double elem;
} Link;

//Link testLink1 = {
//	.elem = {"1234567890123456789012345678901234567890"}
//};
//
//Link testLink2 = {
//	.elem = {"1"}
//};

struct oneByteStruct { char oneB; };
struct ldStruct { char oneB; double ld[40]; };
struct wordStruct { char oneB; int i; };

struct naked		{ char hi; char ho; };
struct dressedup	{ char hi; char ho; char hello[]; };

int main()
{
	printf("sizeof(Link)\t  %d\n", (int)sizeof(Link));
	printf("offsetof(prev)\t%d\n", (int)offsetof(Link, prev));
	printf("sizeof(prev)\t  %d\n", (int)sizeof(((Link*)0)->prev));
	printf("offsetof(next)\t%d\n", (int)offsetof(Link, next));
	printf("sizeof(next)\t  %d\n", (int)sizeof(((Link*)0)->next));
	printf("offsetof(elem)\t%d\n", (int)offsetof(Link, elem));
	printf("sizeof(elem)\t%d\n", (int)sizeof(((Link*)0)->elem));
//	printf("sizeof(testLink1)(char[40])\t  %d\n", (int)sizeof(testLink1));
//	printf("sizeof(testLink2)(char[1])\t  %d\n", (int)sizeof(testLink2));
	printf("\n"); /*  ===================  */
	printf("sizeof(oneByteStruct)\t%d\n", (int)sizeof(struct oneByteStruct));
	printf("sizeof(ldStruct)\t%d\n", (int)sizeof(struct ldStruct));
	printf("offsetof(ld)\t%d\n", (int)offsetof(struct ldStruct, ld));
	printf("sizeof(ld)\t%d\n", (int)sizeof(((struct ldStruct*)0)->ld));
	printf("\n"); /*  ===================  */
	printf("sizeof(wordStruct)\t%d\n", (int)sizeof(struct wordStruct));
	printf("offsetof(int)\t%d\n", (int)offsetof(struct wordStruct, i));
	printf("\n"); /*  ===================  */
	printf("sizeof(naked)\t\t%d\n", (int)sizeof(struct naked));
	printf("sizeof(dressedup)\t%d\n", (int)sizeof(struct dressedup));
}
