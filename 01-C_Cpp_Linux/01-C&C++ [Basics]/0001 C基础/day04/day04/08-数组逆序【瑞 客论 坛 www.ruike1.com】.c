#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 数组元素逆序
int main0801(void)
{
	int arr[] = {1, 6, 8, 0, 4, 3, 9, 2};  // {2, 9, 3, 4, 0, 8, 6, 1}
	int len = sizeof(arr) / sizeof(arr[0]); //数组元素个数

	int i = 0;				// i表示数组的首元素下标
	int j = len - 1;		// 表示数组的最后一个元素下标
	int xijinping = 0;		// 临时变量 

	// 交换 数组元素，做逆序
	while (i < j)
	{
		xijinping = arr[i];		// 三杯水法变量交换
		arr[i] = arr[j];
		arr[j] = xijinping;
		i++;
		j--;
	}
	// 打印交互后的 数组
	for (size_t n = 0; n < len; n++)
	{
		printf("%d ", arr[n]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}

