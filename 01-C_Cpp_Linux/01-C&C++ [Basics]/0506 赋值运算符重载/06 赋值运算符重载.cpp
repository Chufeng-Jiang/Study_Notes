#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//编译器 默认给一个类4个函数   默认构造   析构   拷贝构造 （值拷贝）  operator= (值拷贝)
class Person
{
public:
	Person(char * name, int age)
	{
		this->m_Name = new char[strlen(name) + 1]; // 创建在堆区
		strcpy(this->m_Name, name);
		this->m_Age = age;
	}

	//重载 =
	Person& operator=( const Person &p) //返回引用，可以链式编程 p1=p2=p3
	{
		//如果原来堆区有内容，先释放指针
		if (this->m_Name != NULL)
		{
			delete [] this->m_Name;
			this->m_Name = NULL;
		}

		this->m_Name = new char[strlen(p.m_Name) + 1]; //重新开辟堆区新建一个堆区给本体自己使用
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
		return *this;
	}

	//拷贝构造
	Person(const Person & p)
	{
		// 拷贝构造无需判断是否需要先释放堆区指针，因为一开始本来就是没有的
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}

	~Person()
	{
		if (this->m_Name!=NULL)
		{
			delete [] this->m_Name;
			this->m_Name = NULL;
		}
	}

	char * m_Name;
	int m_Age;
};


void test01()
{
	Person p1("Tom",10);
	
	Person p2("Jerry",19);
	p2 = p1;

	Person p3("", 0);
	p3 = p2 = p1;


	Person p4 = p3;

	cout << "p1姓名： "<< p1.m_Name << "  p1年龄： " << p1.m_Age << endl;
	cout << "p2姓名： "<< p2.m_Name << "  p2年龄： " << p2.m_Age << endl;
	cout << "p3姓名： " << p3.m_Name << " p3年龄： " << p3.m_Age << endl;

}

int main(){

	test01();

	/*int a = 10;
	int b = 20;
	int c;
	c = a = b;
	cout << "a = " << a << " b = " << b << " c = " << c << endl;*/


	system("pause");
	return EXIT_SUCCESS;
}