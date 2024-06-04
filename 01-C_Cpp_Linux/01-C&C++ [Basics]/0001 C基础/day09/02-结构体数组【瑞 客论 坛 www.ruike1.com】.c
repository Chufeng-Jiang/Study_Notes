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
};

int main02(void)
{
	struct student arr[5] = { 10, "andy", 10 ,11, "lucy", 11 ,12, "lily", 12 ,13, "mike", 13 ,14, "marry", 14 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		sum += arr[i].age;
	}
	printf("avg age = %d\n", sum / n);

	system("pause");
	return EXIT_SUCCESS;
}


int main0201(void)
{
	struct student arr[5] = {
		{ 10, "andy", 10 },
		{ 11, "lucy", 11 },
		{ 12, "lily", 12 },
		{ 13, "mike", 13 },
		{ 14, "marry", 14 }
	};

	int n = sizeof(arr) / sizeof(arr[0]);
	for (size_t i = 0; i < n; i++)
	{
		printf("age=%d, name=%s, num=%d\n", arr[i].age, arr[i].name, arr[i].num);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}

int main0203(void)
{
	struct student arr2[5] = {
		10, "andy", 10 ,
		11, "lucy", 11 ,
		12, "lily", 12 ,
		13, "mike", 13 ,
		14, "marry", 14 
	};

	struct student arr[5] = {10, "andy", 10 ,11, "lucy", 11 ,12, "lily", 12 ,13, "mike", 13 ,14, "marry", 14};

	int n = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < n; i++)
	{
		printf("age=%d, name=%s, num=%d\n", arr[i].age, arr[i].name, arr[i].num);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}

int main0202(void)
{
	struct student arr[5];

	arr[0].age = 19;
	strcpy(arr[0].name, "1111");
	arr[0].num = 19;

	(*(arr+1)).age = 191;
	strcpy((*(arr + 1)).name, "2222");
	(*(arr + 1)).num = 192;

	(arr + 2)->age = 193;
	strcpy((arr + 2)->name, "333");
	(arr + 2)->num = 192;

	struct student *p = arr;

	(*(p + 3)).age = 194;
	strcpy((*(p + 3)).name, "444");
	(*(p + 3)).num = 192;

	(p + 4)->age = 196;
	strcpy((p + 4)->name, "444");
	(p + 4)->num = 192;

	int n = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < n; i++)
	{
		printf("age=%d, name=%s, num=%d\n", arr[i].age, arr[i].name, arr[i].num);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}
