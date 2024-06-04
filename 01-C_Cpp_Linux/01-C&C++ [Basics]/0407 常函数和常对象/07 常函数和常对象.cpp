#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->m_Age = age;
	}

	//常函数 ： 修饰成员函数中的 this指针，让指针指向的值不可以修改
	void showPerson() const
	{
		//m_Age = 100;

		m_A = 100;

		//this指针的本质： const Person * const this 
		//this = NULL; 指针的指向不可以修改，而指针指向的值 可以改
		cout << "person age = " << this->m_Age << endl;
	}

	void func()
	{
		m_Age = 100;
		cout << "func调用" << endl;
	}

	int m_Age;

	mutable int m_A; //常函数中或常对象 有些特殊属性依然想修改，加入关键字 mutable
};

void test01()
{
	//常对象
	const Person p1(10);
	//p1.m_Age = 10;
	p1.m_A = 10;

	p1.showPerson();

	//p1.func(); //常对象 只能调用常函数,而不能调用普通的成员函数
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}