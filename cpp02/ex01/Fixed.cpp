#include "Fixed.hpp"

Fixed::Fixed(void)
	: _fixed(0)
{
	std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(int fixed)
	: _fixed(fixed << _bits)
{
	std::cout << "Fixed constructor called." << std::endl;
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	_fixed = raw;
}
