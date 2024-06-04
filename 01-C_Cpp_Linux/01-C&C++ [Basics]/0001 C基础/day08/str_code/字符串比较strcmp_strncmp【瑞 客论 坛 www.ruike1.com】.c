#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int mystrcmp(const char* str1, const char*str2)
{
	if (!str1 || !str2)
		return -2;
		
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	
	return *str1 > *str2 ? 1 : -1;
}

int mystrncmp(const char* str1, char* str2, size_t size)
{
	if (!str1 || !str2)
		return -2;
		
	int i = 0;
	while (*str1 == *str2)
	{
		if (i == size || *str1 == '\0')
			return 0;
		i++;
		str1++;
		str2++;
	}
	
	return *str1 > *str2 ? 1 : -1;
}

int main(void)
{
	char str1[] = "hello world";
	char str2[] = "hello kitty";

	//int value = mystrcmp(str1, str2);
	int value = mystrncmp(str1, str2, 5);
	
	printf("%d\n", value);
	
	if (value == 0)
	{
		printf("相同\n");
	}
	else
	{
		printf("不相同\n");
	}
	
	return EXIT_SUCCESS;
}
