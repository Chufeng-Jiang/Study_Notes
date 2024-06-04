#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// 指针在数组中 +- 整数
int main0601(void)
{
	int a[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };
	//int *p = a; // a == &a[0];

	int *p = &a[5];

	printf("p-2 = %p\n", p - 2);

	printf("&a[3] = %p\n", &a[3]);

	system("pause");
	return EXIT_SUCCESS;
}

// &数组名 +1
int main0602(void)
{
	short a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	printf("a = %p\n", a);
	printf("&a[0] = %p\n", &a[0]);

	printf("a+1 = %p\n", a+1);

	printf("&a   = %p\n", &a);
	printf("&a+1 = %p\n", &a + 1);

	system("pause");
	return EXIT_SUCCESS;
}

// 指针加减指针
int main0603(void)
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = a;

	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", *p);
		p++;
	}
	printf("p - a = %d\n", p - a);

	system("pause");
	return EXIT_SUCCESS;
}
