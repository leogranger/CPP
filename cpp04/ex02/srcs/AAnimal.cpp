#include "AAnimal.hpp"

AAnimal::AAnimal(void)
	: _type("")
{
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type)
	: _type(type)
{
	std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
	: _type(other._type)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called." << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}
