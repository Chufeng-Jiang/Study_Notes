#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	FILE *fp = fopen("test07.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}
	char buf[4096] = {0};

	while (1)
	{
		fgets(buf, 4096, stdin);
		if (strcmp(buf, ":wq\n") == 0)
		{
			break;
		}
		fputs(buf, fp);
	}

	fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}
