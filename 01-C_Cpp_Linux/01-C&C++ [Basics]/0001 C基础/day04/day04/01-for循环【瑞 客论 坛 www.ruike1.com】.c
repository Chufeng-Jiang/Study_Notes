#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 基础for循环
int main0101(void)
{
	int i = 0;		// 循环因子
	int sum = 0;

	for (i = 1; i <= 100; i++)
	{
		sum = sum + i;  //sum += i;
	}

	printf("sum = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}

// 省略表达式1
int main0102(void)
{
	int i = 1;		// 循环因子
	int sum = 0;

	for (; i <= 100; i++)
	{
		sum = sum + i;  //sum += i;
	}

	printf("sum = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}

// 省略表达式3
int main0103(void)
{
	int i = 1;		// 循环因子
	int sum = 0;

	for (; i <= 100; )
	{
		sum = sum + i;  //sum += i;
		i++;
	}

	printf("sum = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}

// 省略表达式123
int main0104(void)
{
	int i = 0;		// 循环因子

	//for (;1;)		// 死循环。while(k=1)
	for (;;)
	{
		printf("i = %d\n", i);
		i++;
	}

	system("pause");
	return EXIT_SUCCESS;
}

// 表达式有多个
int main0105(void)
{
	int i = 0;
	int a = 0;

	for (i = 1, a = 3;a < 20; i++)
	{
		printf("i = %d\n", i);
		printf("a = %d\n", a);
		a += 5;
	}
	system("pause");
	return EXIT_SUCCESS;
}

