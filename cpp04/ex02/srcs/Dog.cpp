#include "Dog.hpp"

Dog::Dog(void)
	: AAnimal()
{
	_type = "Dog";
	DogBrain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}
Dog::Dog(std::string type)
	: AAnimal(type)
{
	DogBrain = new Brain();
	std::cout << "Dog constructor called." << std::endl;
}
Dog::Dog(const Dog& other)
	: AAnimal(other)
{
	DogBrain = new Brain(*other.DogBrain);
	std::cout << "Dog copy constructor called." << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
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