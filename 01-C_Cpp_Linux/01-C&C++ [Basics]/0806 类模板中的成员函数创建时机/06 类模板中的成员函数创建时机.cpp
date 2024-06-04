#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show 调用" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show 调用" << endl;
	}
};


//类模板中的成员函数  并不是一开始创建的，而是在运行阶段确定出T的数据类型才去创建
template<class T>
class MyClass
{
public:
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}

	T obj;
};

void test01()
{
	/*p1.func1()与p2.func2()不能同时运行*/

	MyClass <Person2> p1;
	//p1.func1(); //在class Person1中
	p1.func2(); //在class Person2中
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}