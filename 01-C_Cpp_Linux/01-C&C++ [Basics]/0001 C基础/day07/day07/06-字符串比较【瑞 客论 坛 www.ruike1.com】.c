#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// str1 和 str2  == -->0  str1 > str2 --> 1, str1<str2 --> -1
int mystrcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i])   // *(str1+i) == *(str2+i)
	{
		if (str1[i] == '\0')
		{
			return 0;			// 2字符串一样。
		}
		i++;
	}
	return str1[i] > str2[i] ? 1 : -1;
}

int mystrcmp2(char *str1, char *str2)
{
	while (*str1 == *str2)   // *(str1+i) == *(str2+i)
	{
		if (*str1 == '\0')
		{
			return 0;			// 2字符串一样。
		}
		str1++;
		str2++;
	}
	return *str1 > *str2 ? 1 : -1;
}

int main0601(void)
{
	char *str1 = "helloz";
	char *str2 = "helloz";

	//int ret = mystrcmp(str1, str2);
	int ret = mystrcmp2(str1, str2);

	if (ret == 0)
		printf("相同\n");
	else if (ret == 1)
		printf("str1 > str2\n");
	else if (ret == -1)
		printf("str1 < str2\n");
	else
		printf("异常\n");

	system("pause");
	return EXIT_SUCCESS;
}
