#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int func(int a, char ch);

int main(void)
{
	int ret = func(10, 'a');

	printf("ret = %d\n", ret);

	system("pause");
	//return EXIT_SUCCESS;
	exit(EXIT_SUCCESS);
}

int func(int a, char ch)
{
	printf("a = %d\n", a);

	printf("ch = %c\n", ch);

	//return 10;
	exit(10);
}

