#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void write_rand()
{
	FILE *fp = fopen("test02.txt", "w");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}

	srand(time(NULL)); // 随机数种子

	for (size_t i = 0; i < 10; i++)
	{
		fprintf(fp, "%d\n", rand() % 100);  // 将生成的随机数写入文件
	}
	
	fclose(fp);
}


void BubbleSort(int * src, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (src[j] > src[j + 1])
			{
				int temp = src[j];
				src[j] = src[j + 1];
				src[j + 1] = temp;
			}
		}
	}
}

void read_rand02()
{
	int arr[10], i = 0;

	FILE *fp = fopen("test02.txt", "r");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}

	while (1)
	{
		fscanf(fp, "%d\n", &arr[i]);// 从文件中读取一个随机数，存入数组arr
		i++;
		if (feof(fp))				// 先存储，后判断，防止最后一个元素丢失
			break;
	}
	BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));  // 对读取到的乱序数组排序

	fclose(fp);							// 关闭文件
	fp = fopen("test02.txt", "w");		// 重新w方式打开文件， 清空原未排序文件。
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}
	for (size_t i = 0; i < 10; i++)
		fprintf(fp, "%d\n", arr[i]);	// 写排好序的数组到文件

	fclose(fp);
}

int main0201(void)
{
	write_rand();

	getchar();

	read_rand02();

	system("pause");
	return EXIT_SUCCESS;
}
