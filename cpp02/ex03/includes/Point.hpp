#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(void);
		Point(const Point& other);
		Point(Fixed x, Fixed y);
		~Point(void);
		Point& operator=(const Point& other);
		int	getX(void) const;
		int	getY(void) const;
};

#endif