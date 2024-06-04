#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	int age;
	char name[10];
	int num;
}obj1, obj2;

struct {
	int age;
	char name[10];
	int num;
}obj, *obj4, obj5 = { 100, "abc", 666 };


int main0102(void)
{
	obj4 = &obj5;
	printf("%x\n", obj5.name[0]);

	(*obj4).age = 200;//obj4->age = 200;
	strcpy((*obj4).name,"200");
	(*obj4).num = 200;

	printf("age=%d, name=%s, num=%d\n", obj4->age, obj4->name, obj4->num);

	printf("age=%d, |%s|, num=%d\n", (&obj5)->age, (&obj5)->name, (&obj5)->num);

	system("pause");
	return EXIT_SUCCESS;
}

int main0101(void)
{
	struct student stu = { 18, "afei", 97 };
	struct student stu2;

	stu2.age = 17;
	strcpy(stu2.name, "andy");//stu2.name = "andy";
	stu2.num = 99;

	printf("age = %d, name=%s, num= %d\n", stu2.age, stu2.name, stu2.num);
	printf("age = %d, name=%s, num= %d\n", stu.age, stu.name, stu.num);

	system("pause");
	return EXIT_SUCCESS;
}


