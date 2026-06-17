#include "Cat.hpp"

Cat::Cat(void)
	: AAnimal()
{
	_type = "Cat";
	CatBrain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}
Cat::Cat(std::string type)
	: AAnimal(type)
{
	CatBrain = new Brain();
	std::cout << "Cat constructor called." << std::endl;
}
Cat::Cat(const Cat& other)
	: AAnimal(other)
{
	CatBrain = new Brain(*other.CatBrain);
	std::cout << "Cat copy constructor called." << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		Brain	*tmp = new Brain(*other.CatBrain);
		delete CatBrain;
		CatBrain = tmp;

	}
	std::cout << "Cat copy assignement operator called." << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	
	std::cout << "Cat destructor called." << std::endl;
	delete CatBrain;
}

void	Cat::makeSound(void) const
{
	std::cout << "MEOOOOooOOOOOOoooooow...." << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (CatBrain);
}
