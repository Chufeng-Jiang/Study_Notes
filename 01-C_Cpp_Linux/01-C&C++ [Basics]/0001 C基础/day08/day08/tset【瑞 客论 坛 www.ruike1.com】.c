#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sub(int s[], int y)
{
	static int t = 3;
	y = s[t];
	t--;
}

int main(void)
{

	int a[] = { 1,	2£¬ 3£¬ 4 }£¬ i£¬ x = 0£»
	for (i = 0£» i<4£» i++) {
		sub(a, x)£» 
		printf(£¢£¥d£¢£¬ x)£»
	}
	printf(£¢£Ün£¢)£»

	system("pause");
	return EXIT_SUCCESS;
}
