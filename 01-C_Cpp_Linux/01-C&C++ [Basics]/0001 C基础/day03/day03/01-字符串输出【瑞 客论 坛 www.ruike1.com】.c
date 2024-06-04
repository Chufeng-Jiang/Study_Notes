#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0101(void)
{
	char ch = 'a';

	printf("ch = %c\n", ch);

	char str[20] = "hello world";

	printf("str = %s\n", str);

	system("pause");
	return EXIT_SUCCESS;
}

int main0102(void)
{
	char str[] = "hello world";

	printf("str = |%-15s|\n", str);

	system("pause");
	return EXIT_SUCCESS;
}

int main0103(void)
{
	putchar(97);  // 'a' == 97
	putchar('b');
	putchar('c');
	putchar('d');

	putchar('abcZ');

	system("pause");
	return EXIT_SUCCESS;
}
