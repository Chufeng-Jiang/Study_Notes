#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{	
		cout << "Person的有参构造调用" << endl;
		this->m_Age = age;
	}

	void showAge()
	{
		cout << "年龄为： "<< this->m_Age << endl;
	}

	~Person()
	{
		cout << "Person的析构调用" << endl;
	}

	int m_Age;
};

class SmartPoint
{
public:
	SmartPoint(Person * person)
	{
		this->m_person = person; 
	}

	//重载->运算符
	Person * operator->()
	{
		return this->m_person;
	}

	//重载 解引用* 运算符
	Person& operator*() // 如果返回值是Person，那么只是返回了一个拷贝，返回引用才是返回本体
	{
		return *m_person; 
	}

	// 只能指针托管释放，不用手动delete
	~SmartPoint()
	{
		if (this->m_person)
		{
			delete this->m_person;
			this->m_person = NULL;
		}
	}

private:
	Person * m_person;
};

void test01()
{
	//Person * p = new Person(18);
	//(*p).showAge();
	//p->showAge();
	//delete p;

	//利用智能指针 管理new出来的person的释放操作
	SmartPoint sp(new Person(18)); //new出来的Person给了Person * m_person进行管理，放在栈上，结束的时候会执行析构代码，析构里面就包含了delete操作

	sp->showAge(); // 本质sp->->showAge(); 编译器简化为 sp->showAge();  
	//"sp->" == "this->m_person" => "sp->->showAge()" == "this->m_person->showAge()"

	(*sp).showAge();

}


int main(){
	test01();

	system("pause");
	return EXIT_SUCCESS;
}