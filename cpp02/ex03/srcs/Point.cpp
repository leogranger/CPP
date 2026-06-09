#include "Point.hpp"

Point::Point(void)
	: _x(0)
	, _y(0)
{
	//std::cout << "Point default constructor called." << std::endl;
}

Point::Point(const Fixed x, const Fixed y)
	: _x(x)
	, _y(y)
{
	//std::cout << "Point parameters constructor called." << std::endl;
}

Point::Point(const Point&other)
	: _x(other._x)
	, _y(other._y)
{
	//std::cout << "Point copy constructor called." << std::endl;
}

Point::~Point(void)
{
	//std::cout << "Point destructor called." << std::endl;
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

int	Point::getX(void) const
{
	return (_x.getRawBits());
}

int	Point::getY(void) const
{
	return (_y.getRawBits());
}