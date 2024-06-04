#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0301(void)
{
		int a = 345;

		char ch = 'R';

		void *p;  // 万能指针、泛型指针
		//p = &a;
		p = &ch;

	printf("%c\n", *(char *)p);


	system("pause");
	return EXIT_SUCCESS;
}
