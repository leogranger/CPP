#include "Animal.hpp"

Animal::Animal(void)
	: _type("")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type)
	: _type(type)
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& other)
	: _type(other._type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "...KUKAAAaaaAAAaaAAAAaaa..." << std::endl;
}