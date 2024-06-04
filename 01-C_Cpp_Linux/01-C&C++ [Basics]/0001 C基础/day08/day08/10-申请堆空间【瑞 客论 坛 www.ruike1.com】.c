#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main1001(void)
{
	//int arr[1000000] = {10, 20, 40};
	int *p = (int *)malloc(sizeof(int) * 10);
	//char *str = (char *)malloc(sizeof(char)*10);
	if (p == NULL)
	{
		printf("malloc error\n");
		return -1;
	}
	char *tmp = p;  // 记录malloc返回的地址值。用于free

	// 写数据到 malloc 空间。
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 10;
	}
	// 读出malloc空间中的数据
	//for (size_t i = 0; i < 10; i++)
	//{
	//	printf("%d ", *(p+i));
	//}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", *p);
		p++;
	}

	// 释放申请的内存。
	free(tmp);
	p = NULL;

	system("pause");
	return EXIT_SUCCESS;
}
