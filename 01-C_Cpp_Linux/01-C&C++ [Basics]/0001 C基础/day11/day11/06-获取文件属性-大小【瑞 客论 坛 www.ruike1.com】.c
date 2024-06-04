#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>

/*
FILE *fp = fopen("test05.txt", "r");

fseek(fp, 0, SEEK_END);

int len = ftell(fp);

printf("文件大小：%d\n", len);

fclose(fp);
*/

int main0602(void)
{
	struct stat buf;

	int ret = stat("test05.txt", &buf);  // 传出参数：在函数调用结束时，充当函数返回值。

	printf("文件大小：%d\n", buf.st_size); // 不打开文件，获取文件大小。

	system("pause");
	return EXIT_SUCCESS;
}
