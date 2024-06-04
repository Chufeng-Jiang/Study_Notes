#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/****************************************************
拷贝构造函数调用的时机：

1、用已经创建好的对象来初始化新的对象
2、值传递的方式 给函数参数传值
3、以值方式 返回局部对象
****************************************************/

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int age)
	{
		m_Age = age;
		cout << "Person的有参构造函数调用" << endl;
	}


	//拷贝构造函数
	Person(const Person &p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;

};


//1、用已经创建好的对象来初始化新的对象
void test01()
{
	Person p1(18);

	Person p2 = Person(p1);

	cout << "p2的年龄：" << p2.m_Age<< endl;

}

//2、值传递的方式 给函数参数传值
void doWork(Person p) //做一个接受的操作
{

}
void test02()
{
	//先调用有参构造->拷贝构造->析构两次

	Person p1(100); //传值的操作

	doWork(p1); //调用


}

//3、以值方式 返回局部对象
Person doWork2()
{
	//先调用默认构造->拷贝构造->析构两次
	Person p;
	return p; //返回了一个匿名的拷贝对象p'
}

void test03()
{
	Person p = doWork2(); //把匿名的拷贝对象p'赋值给p
}

/*	
	编译器优化代码后 release版本代码类似以下：
	void doWork2( Person &p ){};

	Person p;
	doWork2(p);
*/



int main(){
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}