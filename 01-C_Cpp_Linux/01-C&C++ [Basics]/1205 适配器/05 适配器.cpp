#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

class MyPrint :public binary_function<int,int,void> // 两个参数的类型+返回值的类型
{
public:
	void operator()(int val , int start)const 
	{
		cout << "val = " << val << " start = " << start <<  " sum = " <<val +  start << endl;
	}
};

/*
std::bind1st和std::bind2nd函数用于将一个二元算子转换成一元算子。
将给定的参数x绑定到二元函数对象F的第一个或第二个形参。
也就是说，将x存储在该包装器中，如果调用该包装器，则将x作为F的第一个或第二个形参传递。
*/

//1、函数对象适配器
void test01()
{
	vector<int>v;

	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加值： " << endl;
	int num;
	cin >> num;

	//将num的值与容器中的值相加，并打印
	for_each(v.begin(), v.end(), bind2nd( MyPrint(), num ) );//1、利用bind2nd 进行绑定，num的值绑定在<int,int,void>第二个参数中

	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));// num的值绑定在<int,int,void>第一个参数中
}

//1、利用bind2nd 进行绑定
//2、继承 public binary_function<参数1 类型,参数2类型,返回值类型>
//3、加const


//2、取反适配器
	//1、利用not1进行取反
	//2、继承 public unary_function<int,bool>
	//3、加const

class GreaterThanFive:public unary_function<int,bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	//一元取反
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterThanFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( bind2nd( greater<int>() , 5 )));

	if (pos != v.end())
	{
		cout << "找到小于5的值为： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//二元取反
	sort(v.begin(), v.end(),  not2 (less<int>()));
	for_each(v.begin(), v.end(), [](int val){cout << val << endl; });
}



void myPrint3( int val , int start) 
{
	cout << val + start << endl;
}
//3、 函数适配器
void test03()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//将函数指针 适配成函数对象  ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint3), 1000));
}


//4、成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "成员函数----姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	void addAge()
	{
		this->m_Age += 100;
	}

	string m_Name;
	int m_Age;
};

//void myPrint4( Person & p)
//{
//	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
//}

void test04()
{
	vector< Person > v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//利用 mem_fun_ref
	for_each(v.begin(), v.end(),  mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main(){

//	test01();
//	test02();
//	test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}