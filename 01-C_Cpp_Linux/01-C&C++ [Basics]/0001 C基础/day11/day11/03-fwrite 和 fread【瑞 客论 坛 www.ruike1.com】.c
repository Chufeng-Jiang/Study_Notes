#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct student {
	int age;
	char name[10];
	int num;
} stu_t;

void write_struct()
{
	stu_t stu[4] = {
		18, "afei", 10,
		20, "andy", 20,
		30, "lily", 30,
		16, "james", 40
	};

	FILE *fp = fopen("test03.txt", "w");
	if (!fp)
	{
		perror("fopen error");
		return -1;
	}

	int ret = fwrite(&stu[0], 1, sizeof(stu_t) * 4, fp);
	if (ret == 0)
	{
		perror("fwrite error");
		return -1;
	}

	printf("ret = %d\n", ret);

	fclose(fp);
}

// 一次读一个元素。
void read_struct()
{
	FILE *fp = fopen("test03.txt", "r");
	if (!fp)
	{
		perror("fopen error");
		return -1;
	}
	stu_t s1;

	int ret = fread(&s1, 1, sizeof(stu_t), fp);
	printf("ret = %d\n", ret);

	printf("age = %d, name=%s, num = %d\n", s1.age, s1.name, s1.num);

	fclose(fp);
}

// 读所有元素
void read_struct2()
{
	FILE *fp = fopen("test03.txt", "r");
	if (!fp)
	{
		perror("fopen error");
		return -1;
	}
	stu_t s1[10];  // stu_t *s1 = malloc(sizeof(stu_t) * 1024);
	int i = 0;
	while (1)
	{
		int ret = fread(&s1[i], 1, sizeof(stu_t), fp);
		//if (ret == 0)		// 替代feof()函数来判断读到文件结尾。
		if (feof(fp))
		{
			break;
		}
		i++;
		printf("age = %d, name=%s, num = %d\n", s1[i].age, s1[i].name, s1[i].num);
	}
	fclose(fp);
}


int main0301(void)
{
	//write_struct();
	read_struct2();

	system("pause");
	return EXIT_SUCCESS;
}
