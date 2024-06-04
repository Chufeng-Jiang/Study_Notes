#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main0201(void)
{
	srand(time(NULL));	//种随机数种子。

	int n = 0;
	int num = rand() % 100;  // 生成随机数

	for (;;)  // while(1)
	{
		printf("请输入猜测的数字：");
		scanf("%d", &n);
		if (n < num)
		{						// for、while、if 如果执行语句只有一条。 { } 可以省略
			printf("猜小了\n");
		}
		else if (n > num)	
			printf("猜大了\n");	
		else
		{
			printf("猜中！！！\n");
			break;			// 跳出
		}
	}
	printf("本尊是：%d\n", num);

	system("pause");

	return 0;
}
