#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base 
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;  //父类中私有属性，子类访问不到，是由编译器给隐藏了
};

class Son : public Base
{
public:
	int m_D;
};


void test01()
{
	//访问不到不代表不继承
	cout << "size of  Son = " << sizeof(Son) << endl; // 结果为16

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}