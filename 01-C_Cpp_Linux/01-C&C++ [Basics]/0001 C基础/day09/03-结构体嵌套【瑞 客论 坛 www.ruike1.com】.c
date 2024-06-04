#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct person {
	int age;
	char name[10];
};

struct student {
	struct person man;
	int score;
};

int main0302(void)
{
	struct student stu = { 18, 21, "BBB" };

	printf("age = %d\n", (&stu)->man.age);
	printf("name = %s\n", (&stu)->man.name);
	printf("score = %d\n", (&stu)->score);


	system("pause");
	return EXIT_SUCCESS;
}

int main0301(void)
{
	struct student stu;

	stu.man.age = 16;
	strcpy(stu.man.name, "zhangsan");
	stu.score = 61;

	printf("age = %d\n", (&stu)->man.age);
	printf("name = %s\n", (&stu)->man.name);
	printf("score = %d\n", (&stu)->score);

	struct student *p = &stu;

	p->man.age = 18;

	strcpy(p->man.name, "AAA");
	p->score = 100;

	printf("age = %d\n", (*p).man.age);
	printf("name = %s\n", (&(p->man))->name);
	printf("score = %d\n", p->score);

	system("pause");
	return EXIT_SUCCESS;
}
