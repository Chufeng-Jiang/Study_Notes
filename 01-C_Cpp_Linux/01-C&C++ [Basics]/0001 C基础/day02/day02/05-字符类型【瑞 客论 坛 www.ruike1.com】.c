#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0501(void)
{
	char ch = 'A';  // 65

	//printf("1 ch = %c\n", ch);
	printf("1 ch = %d\n", ch);

	ch = 'm'; //

	//printf("2 ch = %c\n", ch);
	printf("2 ch = %d\n", ch);

	//ch = 97;
	ch = 'a';	// 97

	//printf("3 ch = %c\n", ch);
	printf("3 ch = %d\n", ch);

	system("pause");
	return EXIT_SUCCESS;
}

// A -- 65 a -- 97 
int main0502(void)
{
	char ch = 'M';
	char var = '5';

	printf("ch = %c\n", ch + 32);
	printf("var = %c\n", var+4);

	printf("'\\n\'µÄÖµÎª=%d\n", '\n');

	system("pause");
	return EXIT_SUCCESS;
}

