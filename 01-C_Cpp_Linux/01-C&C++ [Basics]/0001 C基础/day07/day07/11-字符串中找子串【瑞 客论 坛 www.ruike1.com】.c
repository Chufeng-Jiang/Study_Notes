#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//strstr函数测试
int main1101(void)
{
	char *ret = strstr("hellollollo", "llo");

	printf("ret = %s\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}











int str_times(char *str, char *substr)
{
	int count = 0;
	char *p = strstr(str, substr);  // "llollollo"

	while (p != NULL)
	{
		count++;
		p += strlen(substr);	// p = p+strlen(substr) --> "llollo"
		p = strstr(p, substr);	// 返回： "llo"
	}
	return count;
}
// 统计字符串中，子串出现的次数。
int main1102(void)
{
	char str[] = "helloabclloxyzllo";
	char substr[] = "llo";

	int ret = str_times(str, substr);

	printf("出现%d次\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}
