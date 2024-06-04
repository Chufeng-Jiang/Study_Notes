#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
template<class NAMETYPE, class AGETYPE = int > //类模板中 可以有默认参数
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}
	NAMETYPE m_Name;
	AGETYPE m_Age;
};

void test01()
{
	
	//类模板和函数模板区别：
	//1、类模板不可以使用自动类型推导，只能用显示指定类型
	//2、类模板中 可以有默认参数
	//Person p1("孙悟空", 100);

	Person<string > p1("孙悟空", 100);
	p1.showPerson();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}