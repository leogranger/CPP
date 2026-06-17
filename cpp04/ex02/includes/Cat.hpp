#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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
};

#endif