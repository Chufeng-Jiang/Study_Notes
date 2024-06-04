#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef union test {
	char ch;
	short sh;
	int a;
}test_t;

int main0101(void)
{
	test_t obj;	

	obj.a = 0x87654321;

	printf("&obj    = %p\n", &obj);
	printf("&obj.ch = %p\n", &obj.ch);
	printf("&obj.sh = %p\n", &obj.sh);
	printf("&obj.a  = %p\n", &obj.a);

	printf("sizeof(test_t) = %u\n", sizeof(test_t));

	printf("a  = 0x%x\n", obj.a);
	printf("sh = 0x%x\n", obj.sh);
	printf("ch = 0x%x\n", obj.ch);

	obj.ch = 0xFF;

	printf("a  = 0x%x\n", obj.a);
	printf("sh = 0x%x\n", obj.sh);
	printf("ch = 0x%x\n", obj.ch);

	system("pause");
	return EXIT_SUCCESS;
}

enum  color { red, green = -5, blue, black, pink = 18, yellow };

int main0102(void)
{
	int flg = 2;

	// ......

	if (flg == blue)
	{
		printf("blue is 2\n");
	}
	else
	{
		printf("blue is not 2, blue = %d\n", blue);
	}	
	printf("yellow = %d\n", yellow);

	system("pause");
	return EXIT_SUCCESS;
}