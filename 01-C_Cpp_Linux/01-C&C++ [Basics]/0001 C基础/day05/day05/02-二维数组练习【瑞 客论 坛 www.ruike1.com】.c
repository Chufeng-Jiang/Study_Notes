#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0201(void)
{
/*
56 78 92
45 67 93
29 83 88
93 56 89
72 83 81
*/
	int scores[5][3] = {1, 2, 4, 5, 6, 7, 8, 9};

	int row = sizeof(scores) / sizeof(scores[0]);
	int col = sizeof(scores[0]) / sizeof(scores[0][0]);

	// 获取 5 名学生、3门功课成绩
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			scanf("%c", &scores[i][j]);
		}
	}
	// 求一个学生的总成绩
	for (size_t i = 0; i < row; i++) // 每个学生
	{
		int sum = 0;
		for (size_t j = 0; j < col; j++)// 每个学生的成绩
		{
			sum += scores[i][j];
		}
		printf("第%d个学生的总成绩为：%d\n", i+1, sum);
	}
	//求一门功课的总成绩
	for (size_t i = 0; i < col; i++)  // 第几门功课
	{
		int sum = 0;
		for (size_t j = 0; j < row; j++)  // 每门功课的第几个学生
		{
			sum += scores[j][i];
		}
		printf("第%d门功课的总成绩为：%d\n", i + 1, sum);
	}


	system("pause");
	return EXIT_SUCCESS;
}
