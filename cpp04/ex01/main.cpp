#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const int size = 10;
	Animal* animals[size];

	std::cout << "\n=== Creating animals ===\n" << std::endl;

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();

	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	std::cout << "\n=== Testing sounds ===\n" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << "\n=== Deep copy test ===\n" << std::endl;

	Dog original;

	original.getBrain()->setIdea(0, "I want a bone");

	Dog copy(original);

	std::cout << "Original idea: "
		<< original.getBrain()->getIdea(0)
		<< std::endl;

	std::cout << "Copy idea: "
		<< copy.getBrain()->getIdea(0)
		<< std::endl;

	original.getBrain()->setIdea(0, "I want a steak");

	std::cout << "\nAfter modifying original:\n" << std::endl;

	std::cout << "Original idea: "
		<< original.getBrain()->getIdea(0)
		<< std::endl;

	std::cout << "Copy idea: "
		<< copy.getBrain()->getIdea(0)
		<< std::endl;


	std::cout << "\n=== Deleting animals ===\n" << std::endl;

	for (int i = 0; i < size; i++)
		delete animals[i];

	/*Dog dog1;
	dog1.getBrain()->setIdea(0, "Bone");

	Dog dog2;
	dog2 = dog1;

	dog1.getBrain()->setIdea(0, "Steak");

	std::cout << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << dog2.getBrain()->getIdea(0) << std::endl;*/
    return (0);
}