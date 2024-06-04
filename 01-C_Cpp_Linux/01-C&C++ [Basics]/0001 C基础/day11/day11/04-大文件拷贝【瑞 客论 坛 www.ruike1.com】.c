#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void myfile_cp()
{
	FILE *rfp = fopen("C:\\itcast\\08-freadº¯Êý.avi", "rb");
	FILE *wfp = fopen("C:\\itcast\\mycopy.avi", "wb");

	char buf[4096] = {0};  // »º³åÇø¡£

	int ret = 0;

	while (1)
	{
		memset(buf, 0, sizeof(buf));
		ret = fread(buf, 1, sizeof(buf), rfp);
		if (ret == 0)
		{
			break;
		}
		printf("ret = %d\n", ret);
		fwrite(buf, 1, ret, wfp);
	}

	fclose(wfp);
	fclose(rfp);
}

int main0401(void)
{
	myfile_cp();

	printf("---------------------finish\n");

	system("pause");
	return EXIT_SUCCESS;
}
