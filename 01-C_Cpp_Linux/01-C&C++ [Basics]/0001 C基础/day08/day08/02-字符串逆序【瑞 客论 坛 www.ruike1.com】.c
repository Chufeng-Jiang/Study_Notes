#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


	// o e l l h

// 字符串逆序
void str_inserse(char *str)
{
	//int i, j;  // str[i] *(str+i)
	char *start = str;					// 记录首元素地址
	char *end = str + strlen(str) - 1;	// 记录最后一个元素地址。

	while (start < end)			// 首元素地址是否 < 最后一个元素地址
	{
		char tmp = *start;		// 三杯水 char 元素交换
		*start = *end;
		*end = tmp;
		start++;			// 首元素对应指针后移
		end--;				// 尾元素对应指针前移
	}
}
// 判断回文字符串   abcddpba
int str_abcbb(char *str)
{
	char *start = str;		// 记录首元素地址
	char *end = str + strlen(str) - 1;// 记录最后一个元素地址。

	while (start < end)		// 首元素地址是否 < 最后一个元素地址
	{
		if (*start != *end)	// 判断字符是否一致。
		{
			return 0; // 0 表示非 回文
		}
		start++;
		end--;
	}
	return 1;		// 1 表示 回文
}

int main0201(void)
{
	char str[] = "this is a test";

	str_inserse(str);

	printf("str=%s\n ---------------------\n", str);

	char s2[] = "abcmncba";

	int ret = str_abcbb(s2);

	if (ret == 0)
		printf("不是回文\n");
	else if (ret == 1)
		printf("是回文\n");

	system("pause");
	return EXIT_SUCCESS;
}
