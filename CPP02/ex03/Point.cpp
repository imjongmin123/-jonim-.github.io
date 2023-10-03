#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const Fixed new_x, const Fixed new_y) : x(new_x), y(new_y)
{
}

Point::Point(const Point& pt)
{
	this->x = pt.x;
	this->y = pt.y;
}

Point& Point::operator=(Point& pt)
{
	if (this == &pt)
		return *this;
	this->x = pt.x;
	this->y = pt.y;
	return (*this);
}

float Point::getX() const
{
	return (x.toFloat());
}

float Point::getY() const
{
	return (y.toFloat());
}
