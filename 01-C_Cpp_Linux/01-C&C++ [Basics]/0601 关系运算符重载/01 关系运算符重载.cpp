#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class  Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==( Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}


	bool operator!=(Person & p)
	{
		return !(this->m_Name == p.m_Name && this->m_Age == p.m_Age);
	}


	string m_Name;
	int m_Age;
};

void test01()
{
	//int a = 10;
	//int b = 20;
	//if (a == b)
	//{
	//	cout << "a == b " << endl;
	//}
	//else
	//{
	//	cout << "a != b " << endl;
	//}

	Person p1("Tom", 18);

	Person p2("Tom", 19);

	if (p1 == p2)
	{
		cout << "p1 == p2 " << endl;
	}	
	else
	{
		cout << "a != b " << endl;
	}


	if (p1 != p2)
	{
		cout << "a != b " << endl;
	}
	else
	{
		cout << "p1 == p2 " << endl;
	}

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}