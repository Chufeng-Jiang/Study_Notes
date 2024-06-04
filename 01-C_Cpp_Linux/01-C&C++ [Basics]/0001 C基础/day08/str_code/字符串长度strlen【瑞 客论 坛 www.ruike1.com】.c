#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int my_strlen(const char *str)
{
	char *p = str;

	//while (*p != '\0')
	while (*p)
	{
		p++;
	}

	return p-str;
}

int my_strlen2(const char *str)
{
	char *p = str;

	while (*p++);

	return p - str -1;
}

int main(void)
{
	char str[] = "hello world";

	//int len = my_strlen(str);
	int len = my_strlen2(str);

	printf("len = %d\n", len);

	system("pause");
	
	return EXIT_SUCCESS;
}

