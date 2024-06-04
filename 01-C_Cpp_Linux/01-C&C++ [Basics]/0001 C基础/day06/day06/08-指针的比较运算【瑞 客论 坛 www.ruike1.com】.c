#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0801(void)
{
	int a[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };

	int *p = &a[0];

	if (p > a)
		printf("成立\n");

	else if (p < a)
		printf("不成立\n");

	else
		printf("== \n");



	system("pause");
	return EXIT_SUCCESS;
}
