#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1024		// 定义常量

int main0301(void)
{
	int a = 10;		// 定义变量： 三要素

	short b = 20;

	long c = 30;
	long long d = 40;

	printf("================a===%d\n", sizeof(a));
	printf("================b===%d\n", sizeof(b));
	printf("================c===%d\n", sizeof(c));
	printf("================d===%d\n", sizeof(d));

	printf("int 大小为：%d\n", sizeof(int));
	printf("short 大小为：%d\n", sizeof(short));
	printf("long 大小为：%d\n", sizeof(long));
	printf("long long 大小为：%d\n", sizeof(long long));

	system("pause");

	return EXIT_SUCCESS;
}

int main0302(void)
{
	int a = 3;
	short b = 4;
	long c = 5;			// 5L  5l
	long long d = 6;  // 5LL  5ll

	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(short) = %d\n", sizeof(short));
	printf("sizeof(long) = %d\n", sizeof(long));
	printf("sizeof(long long) = %d\n", sizeof(long long));

	printf("--------------------------------------\n");

	unsigned int aun = 3;		// 3u
	unsigned short bun = 4;		// 3u
	unsigned long cun = 5;		// 3lu
	unsigned long long dun = 6;	// 3llu

	printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int)); // aun
	printf("sizeof(unsigned short) = %d\n", sizeof(unsigned short));
	printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));
	printf("sizeof(unsigned long long) = %d\n", sizeof(unsigned long long));
}
