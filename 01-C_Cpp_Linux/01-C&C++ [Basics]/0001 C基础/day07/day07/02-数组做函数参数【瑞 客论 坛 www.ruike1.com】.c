#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//void BubbleSort(int arr[])  // void BubbleSort(int *arr)

void BubbleSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main0202(void)
{
	int arr[] = {5, 89, 3, 22, 40, 31, 9, 22, 67, 28, 45, 78};

	printf("main: sizeof(arr) = %d\n", sizeof(arr));

	int n = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, n);

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}
