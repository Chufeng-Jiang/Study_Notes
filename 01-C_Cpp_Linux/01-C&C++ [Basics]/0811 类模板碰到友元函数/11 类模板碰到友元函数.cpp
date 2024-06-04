#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//函数模板声明
template<class T1,class T2>
class Person;

template<class T1,class T2>
void printPerson2(Person<T1, T2> &p);

////////////////////////////////////////////////////////////////////////////////////
//声明和实现写在一起
template<class T1,class T2>
void printPerson3(Person<T1, T2>&p)
{
	cout << "类外实现 --- 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

////////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2>
class Person
{
	//1、友元函数 类内实现
	friend void printPerson(Person<T1, T2> &p)
	{
		cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
	}

	//2、友元函数 类外实现,注意要在函数名后面添加"<>",表示是一个模板，并且需要在代码前面做声明
	friend void printPerson2<>(Person<T1, T2> &p);	
	friend void printPerson3<>(Person<T1, T2> &p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

////////////////////////////////////////////////////////////////////////////////////
template<class T1,class T2>
void printPerson2(Person<T1, T2> &p)
{
	cout << "类外实现 --- 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}
////////////////////////////////////////////////////////////////////////////////////
void test01()
{
	Person <string, int> p("Tom", 100);
	printPerson(p);
	printPerson2(p);
	printPerson3(p);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}