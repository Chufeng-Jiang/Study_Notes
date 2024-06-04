#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0401(void)
{
	char src[] = "world";
	char dest[] = "hello";

	char *p = strcat(dest, src);

	printf("p = %s\n", p);
	printf("dest = %s\n", dest);

	system("pause");
	return EXIT_SUCCESS;
}

int main0402(void)
{
	char src[] = "world";
	char dest[6] = "hello";

	char *p = strncat(dest, src, 3);

	printf("p = %s\n", p);
	printf("dest = %s\n", dest);

	printf("%d\n", strlen(dest));

	system("pause");
	return EXIT_SUCCESS;
}

