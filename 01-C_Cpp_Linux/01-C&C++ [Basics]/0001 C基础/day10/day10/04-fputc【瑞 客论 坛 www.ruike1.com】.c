#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0401(void)
{
	char *filename = "test04.txt";

	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}

	int ret = fputc('A', fp);

	printf("ret = %d\n", ret);

	fclose(fp);
	printf("---------------finish\n");

	system("pause");
	return EXIT_SUCCESS;
}

int main0402(void)
{
	char *filename = "test04.txt";
	int ret = 0;

	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}
	char ch = 'a';

	while (ch <= 'z')
	{
		ret = fputc(ch, fp);
		if (ret == -1)
		{
			perror("fputc eror");
			return -1;
		}
		ch++;
	}

	system("pause");
	return EXIT_SUCCESS;
}


int main0403(void)
{
	char *buf = "abcdefghijklmnopqrstuvwxyz";

	char *filename = "test04.txt";
	int ret = 0;

	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}
	int n = strlen(buf);
	for (size_t i = 0; i < n; i++)
	{
		ret = fputc(buf[i], fp);
		if (ret == -1)
		{
			perror("fputc eror");
			return -1;
		}
	}
	fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}




