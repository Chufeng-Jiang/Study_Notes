#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyInter
{
	friend ostream& operator<<(ostream& cout, MyInter& myInt);
public:
	MyInter()
	{
		m_Num = 0;
	}

	//前置++ 重载
	MyInter& operator++() // 返回类型是MyInter的引用，这样就可以链式编程
	{
		this->m_Num++;
		return *this;
	}

	//后置++ 重载
	MyInter operator++(int)
	{
		//先记录初始状态0
		MyInter temp = *this;

		//数字本身+1
		this->m_Num++;

		//返回的是初始的状态0
		return temp; //后置++返回的是值，返回引用的话temp超出作用域就失效了，temp在栈上，用完就消失
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& cout , MyInter& myInt)
{
	cout << myInt.m_Num;
	return cout;
}

void test01()
{
	MyInter myInt;
	cout << ++(++myInt) << endl; 
	cout << myInt << endl; 
}

void test02()
{
	MyInter myInt;

	cout << myInt++ << endl;
	cout << myInt << endl;

}

int main(){
	//test01();
	test02();


	//int a = 0;
	//cout << ++(++a) << endl;
	//cout << a << endl;

	//int b = 0;
	//cout << (b++)++ << endl;

	system("pause");
	return EXIT_SUCCESS;
}