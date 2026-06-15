#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : virtual public Animal
{
	private:
		std::string	_type;
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat(void);
		void	makeSound(void) const;
};

#endif