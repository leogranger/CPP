#include "Dog.hpp"

Dog::Dog(void)
	: Animal()
{
	_type = "Dog";
	DogBrain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}
Dog::Dog(std::string type)
	: Animal(type)
{
	DogBrain = new Brain();
	std::cout << "Dog constructor called." << std::endl;
}
Dog::Dog(const Dog& other)
	: Animal(other)
{
	DogBrain = new Brain(*other.DogBrain);
	std::cout << "Dog copy constructor called." << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		Brain	*tmp = new Brain(*other.DogBrain);
		delete DogBrain;
		DogBrain = tmp;
	}
	std::cout << "Dog copy assignement operator called." << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
	delete DogBrain;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF !!" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (DogBrain);
}