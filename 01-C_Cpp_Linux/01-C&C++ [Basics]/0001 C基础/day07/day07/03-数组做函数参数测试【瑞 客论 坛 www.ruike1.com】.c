#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void test_func(int arr[])
{
	printf("size 2 = %u\n", sizeof(arr));  // 整个数组大小

	printf("%d\n", arr[0]);
}

int main0301(void)
{
	int arr[] = { 4, 5, 5, 6, 7 };

	printf("size 1 = %u\n", sizeof(arr));  // 整个数组大小

	test_func(arr);

	system("pause");
	return EXIT_SUCCESS;
}
