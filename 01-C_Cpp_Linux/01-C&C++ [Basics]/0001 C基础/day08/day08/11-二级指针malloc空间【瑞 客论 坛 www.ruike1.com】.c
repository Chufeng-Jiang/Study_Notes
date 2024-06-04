#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
	int **p = malloc(sizeof(int *) * 3);	// int **p ==> int *p[10]; ==> [ int *, int *, int * ]

	for (size_t i = 0; i < 3; i++)
	{
		p[i] = malloc(sizeof(int) * 5);
	}

	// 使用空间 -- 写
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			p[i][j] = i + j;
		}
	}

	// 使用空间 -- 读
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			printf("%d ", *(*(p+i)+j));  // p[i][j] == *(p+i)[j] == *(*(p+i)+j)
		}
		printf("\n");
	}

	// 释放空间时，应先释放内层空间。
	for (size_t i = 0; i < 3; i++)
	{
		free(p[i]); //*(p+i)
		p[i] = NULL;
	}
	// 释放外层空间
	free(p);
	p = NULL;

	system("pause");
	return EXIT_SUCCESS;
}
