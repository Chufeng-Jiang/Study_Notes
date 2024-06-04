#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 获取用户输入 整数
int main0201(void)
{
	int a;

	scanf("%d", &a);		// &：表示取出变量a的地址。描述a的空间

	printf("a = %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

int main0202(void)
{
	char ch1, ch2, ch3;	//	连续定义同类型多个变量。

	scanf("%c%c%c", &ch1, &ch2, &ch3);	// &：表示取出变量ch的地址。描述a的空间

	printf("ch1 = %c\n", ch1);
	printf("ch2 = %c\n", ch2);
	printf("ch3 = %c\n", ch3);

	system("pause");
	return EXIT_SUCCESS;
}

int main0203(void)
{
	int a1, a2, a3;	//	连续定义同类型多个变量。

	scanf("%d %d %d", &a1, &a2, &a3);	// &：表示取出变量ch的地址。描述a的空间

	printf("a1 = %d\n", a1);
	printf("a2 = %d\n", a2);
	printf("a3 = %d\n", a3);

	system("pause");
	return EXIT_SUCCESS;
}

int main0204(void)
{
	char a[5];			// 大小为5字节的数组

	scanf("%s", a);		// 接收用户键盘输入，写入数组a中

	printf("a = %s\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

int main0205(void)
{
	char a[50];			// 大小为50字节的数组

	scanf("%s", a);		// 接收用户键盘输入，写入数组a中

	printf("a = %s\n", a);

	system("pause");

	return EXIT_SUCCESS;
}

int main0206(void)
{
	char ch;

	ch = getchar();		// 接收用户输入，返回接收到的ASCII码

	printf("ch = %c\n", ch);

	putchar(ch);
	putchar('\n');

	system("pause");

	return EXIT_SUCCESS;
}
