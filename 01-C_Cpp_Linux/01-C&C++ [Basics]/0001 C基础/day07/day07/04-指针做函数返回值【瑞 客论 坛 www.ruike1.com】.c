#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int m = 100;   // 全局变量 对应空间消失 ==> 程序结束。

int *test_func2(int a, int b)
{
	int p = 1234;  // 局部变量
	//return &m;

	return &p;
}

int main0401(void)
{
	int *ret = NULL;  // NULL == 0

	ret = test_func2(10, 20);

	printf("ret = %d\n", *ret);

	system("pause");
	return EXIT_SUCCESS;
}
