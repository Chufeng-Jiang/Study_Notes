#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 隐式类型转换。
int main0601(void)
{
	int a = 321;		

	char ch = a;

	printf("ch = %d\n", ch);

	system("pause");
	return EXIT_SUCCESS;
}

// 强制类型转换
int main0602(int var)
{
	//int *p = (int *)malloc(100);

	float price = 3.6;
	int weight = 4;

	//double sum = (int)price * weight;

	double sum = (int)(price * weight);

	printf("价格：%lf\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}
