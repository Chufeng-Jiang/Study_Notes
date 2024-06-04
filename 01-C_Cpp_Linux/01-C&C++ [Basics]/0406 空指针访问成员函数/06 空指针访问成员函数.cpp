#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Person
{
public:

	void showClass()
	{
		cout << "class Name is Person" << endl;
	}

	void showAge()
	{
		/*	if (this == NULL)
			{
			return;
			}*/
		//m_Age = 0;
		cout << "age = " << this->m_Age << endl;
	}

	int m_Age;
};


void test01()
{
	Person * p = NULL;

	//p->showClass();

	p->showAge();

}

int main(){
	test01();
	system("pause");
	return EXIT_SUCCESS;
}