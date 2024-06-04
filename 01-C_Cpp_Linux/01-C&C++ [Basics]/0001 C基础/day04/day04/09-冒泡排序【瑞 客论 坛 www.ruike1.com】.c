#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0901(void)
{
	int xjp[] = { 12, 32, 14, 62, 27, 8, 89 };

	int n = sizeof(xjp) / sizeof(xjp[0]);	// 数组元素个数

	int temp = 0;		// 临时变量

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", xjp[i]);
	}
	printf("\n");

	// 完成乱序数组的冒泡排序。
	for (size_t i = 0; i < n-1; i++)		// 外层控制行
	{ 
		for (size_t j = 0; j < n - 1 - i; j++)	// 内层控制列
		{
			if (xjp[j] > xjp[j + 1])		// 满足条件 三杯水交换
			{
				temp = xjp[j];
				xjp[j] = xjp[j + 1];
				xjp[j + 1] = temp;
			}
		}
	}

	// 打印排序后的数组，确定正确性。
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", xjp[i]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}
