#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 三目运算
int main0501(void)
{
	int a = 40;
	int b = 4;

	int m = a < b ? 69 : a<b?3:5;  // 嵌套的 三目运算

	printf("m = %d\n", m);

	printf("%d\n", a>b ? 69 : 100);

	system("pause");
	return EXIT_SUCCESS;
}

// 逗号运算符
int main0502(void)
{
	int a = 10, b = 20, c = 30;

	int x = (a = 1,  c = 5, b = 2);		// 逗号运算符。

	printf("x = %d\n", x);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	system("pause");
	return EXIT_SUCCESS;
}

