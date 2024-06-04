#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

enum color { red, black, blue = 10, yellow, pink, green };

int main08(void)
{
	int flg = yellow;

	if (flg == 3)
		printf("flg = yellow\n");

	system("pause");
	return EXIT_SUCCESS;
}
