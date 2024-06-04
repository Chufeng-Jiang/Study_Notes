#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main0301(void)
{
	int i, j, k;

	// 小时
	for (i = 0; i < 24; i++)
	{
		// 分钟
		for (j = 0; j < 60; j++)
		{
			// 秒
			for (k = 0; k < 60; k++)
			{
				printf("%02d:%02d:%02d\n", i, j, k);
				Sleep(960);
				system("cls");  // 清屏
			}
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
