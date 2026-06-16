#include "WrongCat.hpp"

WrongCat::WrongCat(void)
	: WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
}
WrongCat::WrongCat(std::string type)
	: WrongAnimal(type)
{
	std::cout << "WrongCat constructor called." << std::endl;
}
WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat copy assignement operator called." << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MEOOOOooOOOOOOoooooow...." << std::endl;
}
