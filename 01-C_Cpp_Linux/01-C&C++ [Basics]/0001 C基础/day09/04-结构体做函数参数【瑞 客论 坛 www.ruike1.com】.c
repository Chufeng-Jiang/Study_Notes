#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student
{
	int age;
	char name[10];
	int score;
	short num;
};

void func(struct student stu)
{
	printf("func stu: age = %d, name= %s\n", stu.age, stu.name);
	printf("func stu: score = %d, num= %d\n", stu.score, stu.num);

	stu.age = 100;
	strcpy(stu.name, "super man");
	stu.num = 666;
	stu.score = 101;

	printf("2 func stu: age = %d, name= %s\n", stu.age, stu.name);
	printf("2 func stu: score = %d, num= %d\n", stu.score, stu.num);
}

void func2(struct student *stu)
{
	printf("func stu: age = %d, name= %s\n", stu->age, stu->name);
	printf("func stu: score = %d, num= %d\n", stu->score, stu->num);

	stu->age = 100;
	strcpy(stu->name, "super man");
	stu->num = 666;
	stu->score = 101;

	printf("2 func stu: age = %d, name= %s\n", stu->age, stu->name);
	printf("2 func stu: score = %d, num= %d\n", stu->score, stu->num);
}

struct student func3(struct student stu)
{
	printf("func stu: age = %d, name= %s\n", stu.age, stu.name);
	printf("func stu: score = %d, num= %d\n", stu.score, stu.num);

	stu.age = 100;
	strcpy(stu.name, "super man");
	stu.num = 666;
	stu.score = 101;

	printf("2 func stu: age = %d, name= %s\n", stu.age, stu.name);
	printf("2 func stu: score = %d, num= %d\n", stu.score, stu.num);

	return stu;
}

int main0401(void)
{
	struct student stu1 = {15, "ABC", 67, 99};
	struct student stu2 = stu1;

	//func(stu2);		// 实参 给 形参 赋值
	//func2(&stu2);

	stu2 = func3(stu2);

	printf("stu2: age = %d, name= %s\n", stu2.age, stu2.name);
	printf("stu2: score = %d, num= %d\n", stu2.score, stu2.num);

	system("pause");
	return EXIT_SUCCESS;
}
