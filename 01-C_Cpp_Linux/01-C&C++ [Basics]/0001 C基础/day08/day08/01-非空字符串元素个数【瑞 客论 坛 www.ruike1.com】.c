#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int no_space_str(char *str)
{
	int count = 0;

	char *p = str;

	while (*p)
	{
		if (*p != ' ')
		{
			count++;
		}
		p++;
	}
	return count;
}

int main0101(void)
{
	char str[] = "ni chou sha";

	int ret = no_space_str(str);

	printf("%d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}
