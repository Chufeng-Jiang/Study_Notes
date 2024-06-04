#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "person.hpp"
#include <string>

void test01()
{
	Person<string, int> P("Jerry", 20);
	P.showPerson();
}


int main(){

	test01();

	
	system("pause");
	return EXIT_SUCCESS;
}