#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main1001(void)
{
	int a = 10;
	int *p = &a;
	int **pp = &p;
	// int **pp = &(&a); ≤ª‘ –Ì£°£°
	int ***ppp = &pp;

	printf("***ppp = %d\n", ***ppp);
	printf("**pp = %d\n", **pp);
	printf("*p = %d\n", *p);
	printf("a = %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}
