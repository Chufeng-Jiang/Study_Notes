#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	int a = 5, b = 29, c = 10;

	int arr[10] = {1, 2 ,4, 6, 76, 8, 90 ,4, 3, 6 };  //int a = 109;

	printf("&arr[0] = %p\n", &arr[0]);  // 取数组首元素的地址

	printf("arr = %p\n", arr);		// 数组名

	system("pause");
	return EXIT_SUCCESS;
}

int main0702(void)
{
	int a = 5, b = 29, c = 10;

	int arr[12] = { 1, 2 ,4, 6, 76, 8, 90 ,4, 3, 6 , 6, 8};  //int a = 109;

	printf("数组大小：%u\n", sizeof(arr));

	printf("数组元素的大小：%u\n", sizeof(arr[0]));

	printf("数组元素个数：%d\n", sizeof(arr)/ sizeof(arr[0]));

	system("pause");
	return EXIT_SUCCESS;
}

// 数组初始化
int main0703(void)
{
	int arr[10];  //int a = 109;
	arr[0] = 5;
	arr[1] = 6;
	arr[2] = 7;
		
	int n = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	system("pause");
	return EXIT_SUCCESS;
}

