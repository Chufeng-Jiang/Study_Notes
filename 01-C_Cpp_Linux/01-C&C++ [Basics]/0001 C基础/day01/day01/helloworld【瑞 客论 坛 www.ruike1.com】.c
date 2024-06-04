/*
#include <stdio.h>		// #:关键标识符，表示引入头文件； include：引入头文件关键字
						// stdio.h: 系统标准输入、输出库对应的头文件。 给printf函数服务。
						//<>: 使用系统库函数。  "": 用户自定义库函数。
int main(void)			//int: 函数返回值是整型数据。  mian：函数名。程序唯一的入口。必须有，且只有一次。 void：函数调用无需传参。
{						// 函数体 起始位置

	printf("hello world!\n");	// 将 “hellow world”写到屏幕上。 \n: 回车换行
	system("pause");			// 调用 syatem 函数， 实现暂停功能。 

	return 0;			// 返回当前函数调用 --- 退出程序。  0 要跟 main函数的返回值一一对应。
}// 函数体 结束位置
*/

#include <stdio.h>
#include <Windows.h>

int main01(void)			//int: 函数返回值是整型数据。  mian：函数名。程序唯一的入口。必须有，且只有一次。 void：函数调用无需传参。
{						// 函数体 起始位置
	printf("-----------hello world!\n");	// 将 “hellow world”写到屏幕上。 \n: 回车换行
	Sleep(2000);
	system("cls");			// 调用 syatem 函数， 实现清屏功能。 

	return 0;			// 返回当前函数调用 --- 退出程序。  0 要跟 main函数的返回值一一对应。
}