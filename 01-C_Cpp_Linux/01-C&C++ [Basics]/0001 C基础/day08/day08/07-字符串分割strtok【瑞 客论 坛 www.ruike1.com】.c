#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	char str[] = "www.itcast.cn.com.net";  // www itcast cn

	char *p = strtok(str, ".");  // 第一次拆分，参1 传 待拆分的原串。

	while (p != NULL)
	{
		p = strtok(NULL, ".");  // 第1+ 次拆分是，参1传 NULL.

		printf("%s\n", p);
	}
	system("pause");
	return EXIT_SUCCESS;
}


int main0702(void)
{
	char str[] = "www.itcast.cn$This is a strtok$test";

	char *p = strtok(str, "$ .");

	while (p != NULL)
	{
		p = strtok(NULL, ". $");
		printf("p = %s\n", p);
	}

	system("pause");
	return EXIT_SUCCESS;
}
