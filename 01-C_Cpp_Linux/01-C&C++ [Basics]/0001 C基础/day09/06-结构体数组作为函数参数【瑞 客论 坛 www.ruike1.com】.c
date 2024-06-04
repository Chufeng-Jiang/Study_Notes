#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	int age;
	char *name;  // char name[10];  // ջ
	int num;
};

//void init_arr(struct student stu[5])
//void init_arr(struct student stu[])
void init_arr(struct student *stu, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		stu[i].age = i + 10;
		stu[i].name = malloc(10);
		strcpy(stu[i].name, "ABC");
		stu[i].num = i * 10;
	}
}

void print_arr(struct student *stu, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("age = %d\n", stu[i].age);
		printf("name = %s\n", stu[i].name);
		printf("num = %d\n", stu[i].num);
	}
}

int main0601(void)
{
	struct student stu[5];

	int n = sizeof(stu) / sizeof(stu[0]);

	init_arr(stu, n);
	print_arr(stu, n);

	for (size_t i = 0; i < n; i++)
	{
		free(stu[i].name);
	}

	system("pause");
	return EXIT_SUCCESS;
}
