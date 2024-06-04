#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void write_file08()
{
	FILE *fp = fopen("test08.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}

	fputs("10/2=\n", fp);
	fputs("10*3=\n", fp);
	fputs("4-2=\n", fp);
	fputs("10+2=\n", fp);

	fclose(fp);
}

int calc(char ch, int a, int b)
{	
	switch (ch)
	{
	case '/':
		return a / b;
		
	case '+':
		return a + b;
		
	case '-':
		return a - b;
		
	case '*':
		return a *b;	
	default:
		break;
	}
}

void read_file08()
{
	char buf[4096] = {0};
	char result[4096] = {0};

	char sum_res[4096] = {0};

	int a, b, ret;
	char ch;

	FILE *fp = fopen("test08.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}

	while (1)
	{
		fgets(buf, 4096, fp);  //buf = "10/2=\n\0";
		if (feof(fp))
		{
			break;
		}
		sscanf(buf, "%d%c%d=\n", &a, &ch, &b);	// a：10， ch：'/' b: 2

		sprintf(result, "%d%c%d=%d\n", a, ch, b, calc(ch, a, b));  // 10 / 2 = 5;

		strcat(sum_res, result); 
	}
	fclose(fp);  // 将 只有表达式没有结果的文件关闭。

	fp = fopen("test08.txt", "w");	// 清空 只有表达式没有结果的文件
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fputs(sum_res, fp);	// 将 既有表达式又有结果的字符串写到文件中。

	fclose(fp);
}


int main(void)
{
	write_file08();
	getchar();
	read_file08();

	system("pause");
	return EXIT_SUCCESS;
}
