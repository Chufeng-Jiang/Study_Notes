#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef long long int32;

typedef struct student {
	int32 a;
	int32 b;
	int32 c;
	int32 d;
	int32 e;
	int32 f;
}stu_t;		// 给 struct student 类型起了一个别名： stu_t;

int main09(void)
{
	struct student stu;
	stu_t s1;

	s1.a = 10;
	s1.b = 20;

	system("pause");
	return EXIT_SUCCESS;
}
