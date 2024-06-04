#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//×Ö·û´®ÄæÖÃ
void str_inverse(char *str)
{
	char *start = str;
	char *end = str + strlen(str) - 1;

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

int main(void)
{
	char str[] = "hello world";
	
	str_inverse(str);

	printf("%s\n", str);

	return EXIT_SUCCESS;
}