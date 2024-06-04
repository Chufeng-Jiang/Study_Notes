#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// src: 源  dst： 目标
//数组版本
void mystrcpy(char *src, char *dst)
{
	int i = 0;
	while (src[i] != 0)  // src[i] == *(src+i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
//指针版
void mystrcpy2(char *src, char *dst)
{
	while (*src != '\0')  // src[i] == *(src+i)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

int main0701(void)
{
	char *src = "helloworldfuoie11ll";

	char dst[100];

	mystrcpy2(src, dst);

	printf("dst = %s\n", dst);

	system("pause");
	return EXIT_SUCCESS;
}
