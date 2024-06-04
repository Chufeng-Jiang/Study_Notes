#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0301(void)
{
	int a[3][4][2] = 
	{ 
		{
			{1, 2},
			{2, 3},
			{4, 5},
			{5, 6}
		},
		{
			{45, 67},
			{78, 90},
			{12, 6},
			{45, 9}
		},
		{
			{ 45, 67 },
			{ 78, 90 },
			{ 12, 6 },
			{ 45, 9 }
		}
	};

	//int arr[2][3][5] = {1, 2, 4, 5, 6, 7, 8 , 9, 0, 0, 7, 9, 8};
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t k = 0; k < 2; k++)
			{
				printf("%d ", a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}
