#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// hellowrld --- 'm'
char *myStrch(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
		{
			return str;
		}
		str++;
	}
	return NULL;
}

// hellowrld --- 'o'
char *myStrch2(char *str, char ch)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			return &str[i];  
		}
		i++;
	}
	return NULL;
}

int main0801(void)
{
	char str[] = "hello world";
	char ch = ' ';

	char *ret = NULL; 

	ret = myStrch2(str, ch);

	printf("ret = %s\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}
