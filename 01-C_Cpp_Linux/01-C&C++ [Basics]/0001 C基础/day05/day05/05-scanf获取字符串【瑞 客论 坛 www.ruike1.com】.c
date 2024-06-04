#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0501(void)
{
	char str[100];

	//scanf("%s", str);
	scanf("%[^\n]s", str);

	printf("%s\n", str);

	system("pause");
	return EXIT_SUCCESS;
}
