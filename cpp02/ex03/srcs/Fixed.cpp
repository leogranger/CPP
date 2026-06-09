#include "Fixed.hpp"

Fixed::Fixed(void)
	: _fixed(0)
{
	//std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(int fixed)
	: _fixed(fixed << _bits)
{
	//std::cout << "Fixed integer to fixed value constructor called." << std::endl;
}

Fixed::Fixed(float fixed)
	: _fixed(roundf(fixed * (1 << _bits)))
{
	//std::cout << "Fixed float to fixed value constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& other)
	: _fixed(other._fixed)
{
	//std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Fixed destructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;

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

	res.setRawBits(this->getRawBits() * other.getRawBits() >> _bits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() == 0)
	{
		std::cout << "Error: division by 0." << std::endl;
		return 0;
	}
	else
	{
		Fixed res;
		res.setRawBits((this->getRawBits() << _bits) / other.getRawBits());
		return (res);
	}
}

Fixed&	Fixed::operator++(void) //pre-increment
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed&	Fixed::operator--(void) // pre-decrement
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed &a,const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed &a,const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}
