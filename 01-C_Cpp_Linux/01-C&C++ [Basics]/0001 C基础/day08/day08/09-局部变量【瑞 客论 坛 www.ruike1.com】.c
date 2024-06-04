#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void test1(void);  // 全局函数声明

int m = 4456;

int main0901(void)
{
	int i = 10903;

	for (size_t j = 0; j < 10; j++)
	{
		printf("j = %d\n", j);
		//test1();
	}	
	printf("i 2 = %d\n", i);

	system("pause");
	return EXIT_SUCCESS;
}
