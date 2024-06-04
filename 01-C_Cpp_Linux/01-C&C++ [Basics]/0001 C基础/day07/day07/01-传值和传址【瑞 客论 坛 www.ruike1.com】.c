#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int swap(int, int);  // 函数声明
int swap2(int *, int *);

int main0101(void)
{
	int m = 23;
	int n = 57;

	printf("--before-- m = %d, n = %d\n", m, n);
	// 函数调用
	//swap(m, n);  // m/n 实参

	swap2(&m, &n);

	printf("--after-- m = %d, n = %d\n", m, n);

	system("pause");
	return EXIT_SUCCESS;
}

int swap2(int *a, int *b)	// 形参a、b， 需传地址值
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}

// 函数定义
int swap(int a, int b)	// a/b 形参
{
	int tmp = 0;

	tmp = a;
	a = b;
	b = tmp;

	return 0;
}