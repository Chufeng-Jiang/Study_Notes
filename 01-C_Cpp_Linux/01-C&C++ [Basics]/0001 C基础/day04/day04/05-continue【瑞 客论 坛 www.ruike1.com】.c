#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0501(void)
{
	for (size_t i = 0; i < 5; i++)
	{
		if (i == 3)
		{
			continue; 
		}
		printf("i = %d\n", i);
		printf("============1=========\n");
		printf("============2=========\n");
		printf("=============3========\n");
		printf("============4=========\n");
		printf("=============5========\n");

	}

	system("pause");
	return EXIT_SUCCESS;
}


int main0502(void)
{
	int num = 5;

	//while (num--)  // 当num自减为 0 时循环终止。  等价于 while (num-- != 0)

	while (num-- != 0) // 当num自减为 0 时循环终止。
	{ 
		printf("num = %d\n", num);
		if (num == 3)
		{
			continue;
		}
		printf("============1=========\n");
		printf("============2=========\n");
		printf("=============3========\n");
		printf("============4=========\n");
		printf("=============5========\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}
