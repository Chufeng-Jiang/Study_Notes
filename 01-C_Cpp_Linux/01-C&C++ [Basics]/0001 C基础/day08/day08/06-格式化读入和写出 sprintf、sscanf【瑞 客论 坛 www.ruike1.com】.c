#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// sprintf
int main0601(void)
{
	char buf[100] = {0}; //buffer  string str  source src
	 
	sprintf(buf, "%d%c%d=%d\n", 10, '+', 34, 10+34);

	puts(buf);

	system("pause");
	return EXIT_SUCCESS;
}

// sscanf
int main0602(void)
{
	char buf[100] = { 0 }; //buffer  string str  source src

	int a, b, c;

	char str[] = "13+56=89";

	sscanf(str, "%d+%d=%d", &a, &b, &c);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	system("pause");
	return EXIT_SUCCESS;
}
