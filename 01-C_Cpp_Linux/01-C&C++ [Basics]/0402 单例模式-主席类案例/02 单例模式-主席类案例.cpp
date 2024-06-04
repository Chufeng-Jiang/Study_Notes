#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//主席类
class ChairMan
{
public:
    static ChairMan * getInstacne()
	{
		return singleMan;
	}

private:
	//将构造函数私有化，不可以创建多个对象
	ChairMan(){};

	ChairMan(const ChairMan &){};

//public: // 主席指针设置为public的话，外部获取指针就可以直接进行修改。
private:
	//将主席指针 私有化，对外提供只读接口
	static  ChairMan * singleMan; //类内声明  类外初始化
};

ChairMan *  ChairMan::singleMan = new ChairMan; // 加了作用域ChairMan::，则可以访问到类内的东西，编译器会认为这个函数还是在作用域内写的

void test01()
{
	/*ChairMan c1;
	ChairMan c2;
	ChairMan * c3 = new ChairMan;*/

	//ChairMan * c1 = ChairMan::singleMan;
	//ChairMan * c2 = ChairMan::singleMan;


	ChairMan * c1 = ChairMan::getInstacne();
	ChairMan * c2 = ChairMan::getInstacne();

	//ChairMan * c3 = new ChairMan(*c1);

	if (c1 == c2)
	{
		cout << "c1 = c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}

	//if (c1 == c3)
	//{
	//	cout << "c1 = c3" << endl;
	//}
	//else
	//{
	//	cout << "c1 != c3" << endl;
	//}


}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}