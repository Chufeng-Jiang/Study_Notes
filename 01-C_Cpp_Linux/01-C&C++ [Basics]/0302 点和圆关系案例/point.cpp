#include "point.h"

//设置 x 、y
//要记得加上作用域 “Point::”
void Point::setX(int x)
{
	m_X = x;
}
void Point::setY(int y)
{
	m_Y = y;
}

//获取 x 、y
int Point::getX()
{
	return m_X;
}
int Point::getY()
{
	return m_Y;
}
