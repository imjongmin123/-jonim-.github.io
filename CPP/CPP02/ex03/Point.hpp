#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
	Fixed  x;
	Fixed  y;

	public:
	Point();
	~Point();
	Point(const Fixed new_x, const Fixed new_y);
	Point(const Point& pt);
	Point& operator=(Point& pt);

	float getX() const;
	float getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
