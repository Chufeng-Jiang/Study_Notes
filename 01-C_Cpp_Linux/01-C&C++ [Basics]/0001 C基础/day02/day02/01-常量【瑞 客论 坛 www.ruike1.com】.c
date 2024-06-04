#include <stdio.h>

#define PI 3.1415			// 常量

int main01(void)
{
	// 圆的面积  s = PI x 半径的平方
	// 圆的周长  l = 2 * PI * r	
	//int r = 3;				// 变量
	const int r = 3;		// 只读变量

	float s = PI * r * r;
	float l = 2 * PI * r;

	//printf("圆的周长为：%f\n", l);  //18.849001
	//printf("圆的面积为：%f\n", s);  //28.273500

	printf("圆的周长为：%.2f\n", l);	// 指定小数点后保留2位, 对第3位做，4舍五入
	printf("圆的面积为：%.2f\n", s);	// 指定小数点后保留2位

	return 0;
}
