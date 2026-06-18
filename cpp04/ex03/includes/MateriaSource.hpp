#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	inventory[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource(void);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif