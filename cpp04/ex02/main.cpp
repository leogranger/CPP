#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	
	return (0);
}