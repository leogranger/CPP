#include "Dog.hpp"

Dog::Dog(void)
	: Animal()
{
	_type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}
Dog::Dog(std::string type)
	: Animal(type)
{
	std::cout << "Dog constructor called." << std::endl;
}
Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog copy assignement operator called." << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF !!" << std::endl;
}