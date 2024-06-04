#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0401(void)
{
	char str[6] = { 'h', 'e', 'l', 'l', 'o', '\0'};

	char str2[] = "world";  //  == {'w', 'o', 'r', 'l', 'd', '\0'}

	printf("%s\n", str2);

	system("pause");
	return EXIT_SUCCESS;
}

// 统计字符串中每个字符出现的次数
int main0402(void)
{
	char str[11] = {0};		// helloworld -->  26个英文字母 a-z  a:97 d:100

	// scanf("%s", str);
	for (size_t i = 0; i < 10; i++)
	{
		scanf("%c", &str[i]);
	}

	int count[26] = {0};  // 代表26个英文字母出现的次数。 

	for (size_t i = 0; i < 11; i++)
	{
		int index = str[i] - 'a';	// 用户输入的字符在 count数组中的下标值。
		count[index]++;
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c字符在字符串中出现 %d 次\n", i+'a', count[i]);
		}
	}
	
	system("pause");
	return EXIT_SUCCESS;
}

