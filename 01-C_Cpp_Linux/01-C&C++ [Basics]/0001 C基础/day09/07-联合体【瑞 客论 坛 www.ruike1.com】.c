#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

union test {
	char a;
	short b;
	int c;
	char str[13];
};

int main0701(void)
{
	union test t1;

	t1.c = 0x87654321;

	printf("&t1 = %p\n", &t1);
	printf("&t1.a = %p\n", &(t1.a));
	printf("&t1.b = %p\n", &(t1.b));
	printf("&t1.c = %p\n", &(t1.c));

	printf("a = %x\n", t1.a);
	printf("b = %x\n", t1.b);
	printf("c = %x\n", t1.c);

	t1.b = 0x3A;

	printf("----------------\na = %x\n", t1.a);
	printf("b = %x\n", t1.b);
	printf("c = %x\n", t1.c);

	printf("sizeof(t1) = %u\n", sizeof(t1));

	system("pause");
	return EXIT_SUCCESS;
}
