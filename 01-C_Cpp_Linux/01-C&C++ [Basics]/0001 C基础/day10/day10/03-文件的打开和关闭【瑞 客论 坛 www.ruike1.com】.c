#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0301(void)
{
	FILE *fp = NULL;

	fp = fopen("test2.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");  //printf("fopen error\n");  :xxxxxxx
		getchar();
		return -1;
	}

	fclose(fp);
	printf("------------finish\n");

	system("pause");
	return EXIT_SUCCESS;
}
