#include "Fixed.hpp"

Fixed::Fixed(void)
	: _fixed(0)
{
	std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(int fixed)
	: _fixed(fixed << _bits)
{
	std::cout << "Fixed integer to fixed value constructor called." << std::endl;
}

Fixed::Fixed(float fixed)
	: _fixed(roundf(fixed * (1 << _bits)))
{
	std::cout << "Fixed float to fixed value constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& other)
	: _fixed(other._fixed)
{
	std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed destructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_fixed = other._fixed;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called." << std::endl;
	return (_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed = raw;
}

int		Fixed::toInt( void ) const
{
	return (getRawBits() >> _bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)getRawBits() / (1 << _bits));
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (other.getRawBits() > this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (other.getRawBits() < this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (other.getRawBits() >= this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (other.getRawBits() <= this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (other.getRawBits() == this->getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (other.getRawBits() != this->getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() + other.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() - other.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() * other.getRawBits());
	return (res);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() == 0)
	{
		std::cout << "Error division by 0" << std::endl;
	}
	else
	{
		Fixed res;
		res.setRawBits(this->getRawBits() + other.getRawBits());
		return (res);
	}
}

Fixed&	Fixed::operator++(void) //pre-increment
{

}

Fixed	Fixed::operator++(int)
{
	return (this->getRawBits() +)
}

Fixed&	Fixed::operator--(void) // pre-decrement
{

}

Fixed	Fixed::operator--(int)
{

}
