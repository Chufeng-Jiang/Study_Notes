#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0601(void)
{
	printf("============1==========\n");
	printf("============2==========\n");
	goto LABLE;

	printf("============3==========\n");
	printf("============4==========\n");
	printf("============5==========\n");
	printf("============6==========\n");
	printf("============7==========\n");

LABLE:
	printf("============8==========\n");
	printf("============9==========\n");
	printf("============10==========\n");

	system("pause");
	return EXIT_SUCCESS;
}

int main0602(void)
{
	int i = 0;

	for ( i = 0; i < 10; i++)
	{
		if (i == 5)
			goto ABX234;

		printf("i = %d\n", i);
	}

	for (int j = 0; j < 20; j++)
	{
ABX234:
		printf("j = %d\n", j);
	}

	system("pause");
	return 0;
}


