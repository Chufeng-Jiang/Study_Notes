#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void bubble_sort(int arr[]);  // 函数声明
void print_arr(int arr[]);

int main0801(void)
{
	printf("add = %d\n", add(2, 6));

	int arr[] = {54, 5, 16, 34 , 6, 9, 34, 1, 7, 93};

	bubble_sort(arr);

	print_arr(arr);

	system("pause");

	return EXIT_SUCCESS;   // 底层 调用 _exit(); 做退出
}

void print_arr(int arr[])
{
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

void bubble_sort(int arr[])
{
	int i, j, temp;

	for (i = 0; i < 10 - 1; i++)
	{
		for (j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int add(int a, int b)
{
	return a + b;
}



