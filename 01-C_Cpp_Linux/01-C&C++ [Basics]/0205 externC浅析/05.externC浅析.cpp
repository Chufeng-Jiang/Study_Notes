#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "test.h"


//告诉编译器  show函数用C语言方式 做链接
//extern "C" void show();




void test01()
{
	show();//_Z4showv;在C++中有函数重载会修饰函数名，但是show是c语言文件，因此链接失败
}



int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}