#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 指针数组1
int main0901(void)
{
	int a = 10;
	int b = 20;
	int c = 30;

	int *p1 = &a;
	int *p2 = &b;
	int *p3 = &c;

	int *arr[] = {p1, p2, p3};  // 整型指针数组arr， 存的都是整型地址。

	printf("*(arr[0]) = %d\n", *(*(arr + 0)));  //arr[0] ==  *(arr+0)

	printf("*(arr[0]) = %d\n", **arr);

	system("pause");
	return EXIT_SUCCESS;
}
// 指针数组2
int main0902(void)
{
	int a[] = { 10 };
	int b[] = { 20 };
	int c[] = { 30 };

	int *arr[] = { a, b, c };  // 整型指针数组arr， 存的都是整型地址。

	printf("*(arr[0]) = %d\n", *(*(arr + 0)));  //arr[0] ==  *(arr+0)

	printf("*(arr[0]) = %d\n", **arr);

	system("pause");
	return EXIT_SUCCESS;
}
