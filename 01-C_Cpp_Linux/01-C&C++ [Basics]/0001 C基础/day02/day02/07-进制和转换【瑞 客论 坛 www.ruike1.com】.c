#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	int a = 0x2C;  // 等价 0x2c 

	printf("10进制显示 a = %d\n", a);
	printf("8进制显示 a = %o\n", a);
	printf("16进制显示 a = %x\n", a);

	system("pause");
	return EXIT_SUCCESS;
}
