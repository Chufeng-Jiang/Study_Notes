#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0401(void)
{
	size_t var = 10;
	printf("var = %u\n", var);

	unsigned int a = 10u;  // 简写成 unsigned int a = 10;
	unsigned short b = 20u;// 简写成 unsigned short b = 20;
	unsigned long c = 30Lu; 
	unsigned long long d = 40LLu;

	printf("unsigned int 型数据值：%u\n", a);
	printf("unsigned short 型数据值：%hu\n", b);
	printf("unsigned long 型数据值：%lu\n", c);
	printf("unsigned long long 型数据值：%llu\n", d);

	system("pause");

	return EXIT_SUCCESS;
}
