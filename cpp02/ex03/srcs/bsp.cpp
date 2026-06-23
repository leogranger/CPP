#include "Fixed.hpp"
#include "Point.hpp"

Fixed	getTriArea(Point const a, Point const b, Point const c)
{
	Fixed area = (
		a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY())
		) / Fixed(2);
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed AreaOne = getTriArea(a, b, point);
	Fixed AreaTwo = getTriArea(a, c, point);
	Fixed AreaThree = getTriArea(b, c, point);
	Fixed AreaTotal = getTriArea(a, b ,c);

	if (AreaOne == 0 || AreaTwo == 0 || AreaThree == 0)
		return (false);
	else if (AreaOne + AreaTwo + AreaThree == AreaTotal)
		return (true);
	else
		return (false);
}
