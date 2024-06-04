#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 敲 7 
int main0901(void)
{
	int num = 1;

	while (num <= 100)
	{
		if ((num % 7 == 0) || (num % 10 == 7) || (num / 10 == 7))		// 个位、10位、7的倍数
		{
			printf("敲桌子\n");
		}
		else
		{
			printf("%d\n", num);
		}
		num++;  // 递增
	}

	system("pause");
	return EXIT_SUCCESS;
}
