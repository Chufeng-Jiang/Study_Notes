#include <stdio.h>


int main(void)
{

	int a = 3;		// 定义 整型变量 a， 赋初值 3

	int b = 5;		// 定义 整型变量 b， 赋初值 5
	int c;			// 定义 整型变量 c， 无初值
	
	c = a + b;		// a + b ,将结果 赋值 给 c

	printf("hello world\n");

	// %d:格式匹配符，匹配整型数据

	printf("%d\n", c /*注释*/ );	


	printf("c = %d\n", c);

	printf("%d + %d = %d\n", a, b, c);

	printf("%d + %d = &d\n", a, b, a+b);

	return 0;
}
