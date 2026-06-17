#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:

		std::string	_type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual	~AAnimal(void);
		std::string	getType(void) const;
		void	setType(std::string type);
		virtual void	makeSound(void) const = 0;
};

#endif