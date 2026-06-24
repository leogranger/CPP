#include "Fixed.hpp"
#include "Point.hpp"

Fixed	sign(Point const a, Point const b, Point const c)
{
	return (((b.getX() - a.getX()) * (c.getY() - a.getY()))
		- ((b.getY() - a.getY()) * (c.getX() - a.getX())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = sign(a, b, point);
	Fixed d2 = sign(b, c, point);
	Fixed d3 = sign(c, a, point);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(hasNeg && hasPos);
}
