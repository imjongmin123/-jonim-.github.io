#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	float areaABC = 0.5 * fabs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	float areaPBC = 0.5 * fabs(p.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - p.getY()) + c.getX() * (p.getY() - b.getY()));
	float areaPCA = 0.5 * fabs(a.getX() * (c.getY() - p.getY()) + p.getX() * (a.getY() - c.getY()) + c.getX() * (p.getY() - a.getY()));
	float areaPAB = 0.5 * fabs(a.getX() * (b.getY() - p.getY()) + b.getX() * (p.getY() - a.getY()) + p.getX() * (a.getY() - b.getY()));
	return (areaPBC + areaPCA + areaPAB == areaABC);
}