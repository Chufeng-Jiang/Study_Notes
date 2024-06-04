#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "circle.h"
#include "point.h"
/*
设计一个圆形类（AdvCircle），和一个点类（Point），计算点和圆的关系。
假如圆心坐标为x0, y0, 半径为r，点的坐标为x1, y1：
*/

/**********************************
//点类
class point
{
public:

	//设置 x 、y
	void setx(int x)
	{
		m_x = x;
	}
	void sety(int y)
	{
		m_y = y;
	}
	//获取 x 、y
	int getx()
	{
		return m_x;
	}
	int gety()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};


//圆类
class circle
{
public:
	//设置半径
	void setr(int r)
	{
		m_r = r;
	}
	//获取半径
	int getr()
	{
		return m_r;
	}

	//设置圆心
	void setcenter(point p)
	{
		m_center = p;
	}

	//获取圆心
	point getcenter()
	{
		return m_center;
	}

	//判断点和圆关系
	void isincirclebyclass(point p)
	{

		int distance = (m_center.getx() - p.getx())*(m_center.getx() - p.getx()) + (m_center.gety() - p.gety()) *(m_center.gety() - p.gety());

		int rdistance = m_r * m_r;

		if (distance == rdistance)
		{
			cout << "成员函数判断：点在圆上" << endl;
		}
		else if (distance > rdistance)
		{
			cout << "成员函数判断：点在圆外" << endl;
		}
		else
		{
			cout << "成员函数判断：点在圆内" << endl;
		}
	}

private:

	int m_r; //半径

	point m_center; // 圆心
};


*******************************/

//利用全局函数 判断点和圆关系
void isInCircle( Circle c , Point p )
{

	int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) *(c.getCenter().getY() - p.getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}

}

void test01()
{
	Point p;
	p.setX(10);
	p.setY(9);

	Circle c;
	Point pCenter;
	pCenter.setX(10);
	pCenter.setY(0);
	c.setCenter(pCenter);
	c.setR(10);

	isInCircle(c, p); //全局函数，两个参数

	c.isInCircleByClass(p); //成员函数，调用

}


class A
{
	virtual void func() = 0;
};
class B :public A
{

};
class C :public B
{
};

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}