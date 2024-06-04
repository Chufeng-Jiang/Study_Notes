#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// while 的基础用法
int main1001(void)
{
	int a = 1;
	do
	{
		a++;
		printf("a = %d\n", a);
	} while (a < 10);

	system("pause");
	return EXIT_SUCCESS;
}

// 水仙花数：一个三位数。各个位上的数字的立方和等于本数字。 
int main1002(void)
{
	int a, b, c;
	int num = 100;

	do {
		a = num % 10;		// 个位
		b = num / 10 % 10;	// 十位
		c = num / 100;		// 百位

		if (a*a*a + b*b*b + c*c*c == num)
		{
			printf("%d\n", num);
		}
		num++;

	} while (num < 1000);

	system("pause");
	return EXIT_SUCCESS;
}


