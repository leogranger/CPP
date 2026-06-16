#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:

		std::string	_type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual	~Animal(void);
		std::string	getType(void) const;
		void	setType(std::string type);
		virtual void	makeSound(void) const;
};

#endif