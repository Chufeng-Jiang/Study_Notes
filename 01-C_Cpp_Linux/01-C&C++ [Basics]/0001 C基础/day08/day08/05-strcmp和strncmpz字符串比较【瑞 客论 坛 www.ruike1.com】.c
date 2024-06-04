#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0501(void)
{
	char *str1 = "helloworld";
	char *str2 = "helloz";

	printf("ret = %d\n", strcmp(str1, str2));

	system("pause");
	return EXIT_SUCCESS;
}

int main0502(void)
{
	char *str1 = "helloworld";
	char *str2 = "helloz";

	printf("ret = %d\n", strncmp(str1, str2, 8));

	system("pause");
	return EXIT_SUCCESS;
}

