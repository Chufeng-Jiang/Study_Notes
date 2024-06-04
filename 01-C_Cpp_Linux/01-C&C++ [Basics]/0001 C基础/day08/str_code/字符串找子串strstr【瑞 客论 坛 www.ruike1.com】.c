#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char *my_strstr(char *str, char *substr)
{
	char *pstr = str;		// 遍历 str 的指针
	char *temp = str;		// 记录回滚位置的指针
	char *psub = substr;		// 遍历 substr 的指针

	while (*pstr)			// 遍历 原字符串。	
	{
		temp = pstr;		// 记录位置									

		while (*pstr == *psub && *pstr != '\0')				
		{
			pstr++;			// 一起向后走
			psub++;			// 一起向后走
		}
		if (*psub == '\0')								
		{
			return temp;
		}
		// 回滚
		psub = substr;											
		pstr = temp;												

		pstr++;			// 向后走一个字符。								
	}
	
	return NULL;
}

int main(void)
{
	char str[] = "helhellolo world";
	char substr[] = "hello";
	
	printf("%s\n", my_strstr(str, substr));
	
	system("pause");
	
	return EXIT_SUCCESS;
}
