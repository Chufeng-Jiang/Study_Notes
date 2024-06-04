#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0101(void)
{
	int a = 10;

	int *p = &a;

	//*p = 2000;
	a = 350;

	//printf("a = %d\n", a);
	printf("*p = %d\n", *p);
	
	printf("sizeof(int *) = %u\n", sizeof(int *));
	printf("sizeof(short *) = %u\n", sizeof(short *));
	printf("sizeof(char *) = %u\n", sizeof(char *));
	printf("sizeof(long *) = %u\n", sizeof(long *));
	printf("sizeof(double *) = %u\n", sizeof(double *));

	printf("sizeof(void *) = %u\n", sizeof(void *));



	system("pause");
	return EXIT_SUCCESS;
}


