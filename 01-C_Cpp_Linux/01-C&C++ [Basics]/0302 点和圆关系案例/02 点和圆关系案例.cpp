#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "circle.h"
#include "point.h"
/*
���һ��Բ���ࣨAdvCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��
����Բ������Ϊx0, y0, �뾶Ϊr���������Ϊx1, y1��
*/

/**********************************
//����
class point
{
public:

	//���� x ��y
	void setx(int x)
	{
		m_x = x;
	}
	void sety(int y)
	{
		m_y = y;
	}
	//��ȡ x ��y
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


//Բ��
class circle
{
public:
	//���ð뾶
	void setr(int r)
	{
		m_r = r;
	}
	//��ȡ�뾶
	int getr()
	{
		return m_r;
	}

	//����Բ��
	void setcenter(point p)
	{
		m_center = p;
	}

	//��ȡԲ��
	point getcenter()
	{
		return m_center;
	}

	//�жϵ��Բ��ϵ
	void isincirclebyclass(point p)
	{

		int distance = (m_center.getx() - p.getx())*(m_center.getx() - p.getx()) + (m_center.gety() - p.gety()) *(m_center.gety() - p.gety());

		int rdistance = m_r * m_r;

		if (distance == rdistance)
		{
			cout << "��Ա�����жϣ�����Բ��" << endl;
		}
		else if (distance > rdistance)
		{
			cout << "��Ա�����жϣ�����Բ��" << endl;
		}
		else
		{
			cout << "��Ա�����жϣ�����Բ��" << endl;
		}
	}

private:

	int m_r; //�뾶

	point m_center; // Բ��
};


*******************************/

//����ȫ�ֺ��� �жϵ��Բ��ϵ
void isInCircle( Circle c , Point p )
{

	int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) *(c.getCenter().getY() - p.getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
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

	isInCircle(c, p); //ȫ�ֺ�������������

	c.isInCircleByClass(p); //��Ա����������

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