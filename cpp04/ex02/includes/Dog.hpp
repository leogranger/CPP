#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain*	DogBrain;
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog(void);
		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};

#endif