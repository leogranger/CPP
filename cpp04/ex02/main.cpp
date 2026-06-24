#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n=== Polymorphism Test ===\n";

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n=== AAnimal Array Test ===\n";

    AAnimal* AAnimals[10];

    for (int i = 0; i < 5; i++)
        AAnimals[i] = new Dog();

    for (int i = 5; i < 10; i++)
	 AAnimals[i] = new Cat();


    for (int i = 0; i < 10; i++)
	delete AAnimals[i];

    std::cout << "\n=== Copy Constructor Test ===\n";

    Dog originalDog;

    {
        Dog copyDog(originalDog);
    }

    std::cout << "Original Dog still alive.\n";

    std::cout << "\n=== Assignment Operator Test ===\n";

    Dog dog1;
    Dog dog2;

    dog2 = dog1;

    std::cout << "\n=== Cat Copy Test ===\n";

    Cat originalCat;

    {
        Cat copyCat(originalCat);
    }

    std::cout << "Original Cat still alive.\n";

    return 0;
}