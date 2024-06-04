#define _CRT_SECURE_NO_WARNINGS

#include "head.h"

int main(void)
{
	int a = 5;
	int b = 35;

	printf("%d + %d = %d\n", a, b, add(a, b));
	printf("%d - %d = %d\n", a, b, sub(a, b));
	printf("%d x %d = %d\n", a, b, mul(a, b));

	system("pause");
	return EXIT_SUCCESS;
}


