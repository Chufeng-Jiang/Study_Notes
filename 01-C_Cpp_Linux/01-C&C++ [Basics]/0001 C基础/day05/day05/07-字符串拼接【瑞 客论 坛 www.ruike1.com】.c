#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0702(void)
{
	char str1[] = "hello";  // [ h e l l o \0 ]
	char str2[] = "world";

	char str3[100];

	int i = 0;		// 循环 str1
	while (str1[i] != '\0')   // '\0' != '\0'
	{
		str3[i] = str1[i];  // 循环着将str1中的每一个元素，交给str3
		i++;
	}					// str3=[h e l l o]
	//printf("%d\n", i);  --> 5

	int j = 0;		// 循环 str2
	while (str2[j]) // 等价于 while(str2[j] !='\0') 等价于 while(str2[j] != 0)
	{
		str3[i+j] = str2[j];
		j++;
	}					// str3=[h e l l o w o r l d]

	// 手动添加 \0 字符串结束标记
	str3[i + j] = '\0';

	printf("str3 = %s\n", str3);

	system("pause");
	return EXIT_SUCCESS;
}
