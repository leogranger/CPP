#include "Cat.hpp"

Cat::Cat(void)
	: Animal()
{
	_type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}
Cat::Cat(std::string type)
	: Animal(type)
{
	std::cout << "Cat constructor called." << std::endl;
}
Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat copy assignement operator called." << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOOOOooOOOOOOoooooow...." << std::endl;
}
