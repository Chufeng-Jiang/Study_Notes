#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void write_file()
{
	FILE *fp = fopen("abc.c", "w");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}

	fprintf(fp, "%d\n", 10);
	fprintf(fp, "%d\n", 8);
	fprintf(fp, "%d\n", 6);

	fclose(fp);
}

void read_file()
{
	int a;

	FILE *fp = fopen("abc.c", "r");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}

	fscanf(fp, "%d\n", &a);
	printf("%d\n" , a);

	fscanf(fp, "%d\n", &a);
	printf("%d\n", a);

	fscanf(fp, "%d\n", &a);
	printf("%d\n", a);

	a = 0;
	fscanf(fp, "%d\n", &a);
	printf("%d\n", a);

	fclose(fp);
}

// fscanf 循环读文件
void read_file2()
{
	int a;

	FILE *fp = fopen("abc.c", "r");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}
	while (1)
	{
		fscanf(fp, "%d\n", &a);  // 读
		printf("%d\n", a);
		if (feof(fp))		// 真-- 文件结尾
			break;
	}

	fclose(fp);
}

// fgets 循环读文件
void read_file3()
{
	char buf[1024];
	FILE *fp = fopen("abc.c", "r");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}
	while (1)
	{
		memset(buf , 0, 1024);
		fgets(buf, 1024, fp);// 读 \n
		if (feof(fp))		// 真-- 文件结尾
			break;
		printf("%d\n", buf[0]);
	}

	fclose(fp);
}

int main0101(void)
{
	//write_file();
	read_file3();

	system("pause");
	return EXIT_SUCCESS;
}


int main(void)
{
	FILE *fp = fopen("test0101.txt", "r");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}

	int a;
	char ch;
	char str[10];

	int ret = fscanf(fp, "%d %c %s", &a, &ch, str);
	printf("ret = %d\n", ret);

	fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}



