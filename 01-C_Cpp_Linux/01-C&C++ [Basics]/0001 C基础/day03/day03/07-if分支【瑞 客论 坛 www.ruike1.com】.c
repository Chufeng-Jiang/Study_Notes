#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	int a;
	scanf("%d", &a);

	if (a > 0)
	{
		printf("a > 0\n");
	}
	else
	{
		printf("a <= 0\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}

//成绩
int main0702(void)
{
	int score;		// 100--90 优 90 -- 70 良好 70 -- 60 及格  < 60 差劲

	printf("请输入学生成绩：");
	scanf("%d", &score);

	if (score>=90 && score <=100)
	{
		printf("优秀\n");
	} 
	else if(score < 90 && score >=70)
	{
		printf("良好\n");
	}
	else if (score < 70 && score >= 60)
	{
		printf("及格\n");
	}
	else
	{
		printf("不及格\n");
	}



	system("pause");
	return EXIT_SUCCESS;
}

// 三只小猪秤体重
int main0703(void)
{
	int pig1, pig2, pig3;

	// if (pig1 > pig2 && pig1 > pig3)
	// pig1 > pig2 ? pig1 : pig2;

	printf("请输入三只小猪的体重:");
	scanf("%d %d %d", &pig1, &pig2, &pig3);

	if (pig1 > pig2)		// 满足，说明pig1最重
	{
		if (pig1 > pig3)
		{
			printf("第一只小猪最重，体重为：%d\n", pig1);
		}
		else
		{
			printf("第3只小猪最重，体重为：%d\n", pig3);
		}
	}   
	else
	{
		if (pig2 > pig3)
		{
			printf("第2只小猪最重，体重为：%d\n", pig2);
		}
		else
		{
			printf("第3只小猪最重，体重为：%d\n", pig3);
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}

