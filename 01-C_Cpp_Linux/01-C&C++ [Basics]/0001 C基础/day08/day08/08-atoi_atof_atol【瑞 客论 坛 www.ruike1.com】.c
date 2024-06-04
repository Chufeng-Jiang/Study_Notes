#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

static int a = 1034673;

void test1(void)
{
	static int b = 0;

	printf("b = %d\n", b++);
}


int main0801(void)
{
	char str[] = "abc345";
	int num = atoi(str);
	printf("num = %d\n", num);

	char str1[] = "     -10";
	int num1 = atoi(str1);
	printf("num1 = %d\n", num1);

	char str2[] = "0.123f";
	double num2 = atof(str2);
	printf("num2 = %.2lf\n", num2);

	char str3[] = "123L";
	long num3 = atol(str3);
	printf("num3 = %ld\n", num3);

	system("pause");
	return EXIT_SUCCESS;
}
