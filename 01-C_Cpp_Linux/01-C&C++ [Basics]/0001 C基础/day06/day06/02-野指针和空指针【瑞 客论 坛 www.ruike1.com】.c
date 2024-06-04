#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 野指针1
int main0201(void)
{
	/*
	int *p;

	*p = 2000;

	printf("*p = %d\n", *p);
	*/
	system("pause");
	return EXIT_SUCCESS;
}

// 野指针2
int main0202(void)
{
	int m;
	//int *p = 1000;   // 0-255 确定留给操作系统
	int *p = 0x0bfcde0000;

	p = &m;

	*p = 2000;

	printf("*p = %d\n", *p);

	system("pause");
	return EXIT_SUCCESS;
}

// 空指针
int main0203(void)
{
	int *p = NULL;   // NULL == 0

	// .....
	// lllll

	// .....

	if (p != NULL)
	{
		*p = 300;
		printf("*p = %d\n", *p);
	}

	system("pause");
	return EXIT_SUCCESS;
}
