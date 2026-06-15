#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : virtual public Animal
{
	private:
		std::string	_type;
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog(void);
		void	makeSound(void) const;
};

#endif