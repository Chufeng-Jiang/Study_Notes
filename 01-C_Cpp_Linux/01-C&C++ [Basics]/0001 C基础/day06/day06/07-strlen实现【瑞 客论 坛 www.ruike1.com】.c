#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int mystrlen(char arr[]);

int main0701(void)
{
	char abc[] = "hello world";

	int ret = mystrlen2(abc);  // 实际参数 abc

	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}

// 借助数组 实现 
int mystrlen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

// 借助指针++ 实现 
int mystrlen2(char str[])
{
	char *p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p-str;  // 返回数组元素的个数。
}

