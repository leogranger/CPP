#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	CatBrain;
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat(void);
		void	makeSound(void) const;
		Brain*	getBrain(void) const;
		void	setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};

#endif