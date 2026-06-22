#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	index = 0;
	std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for(int i = 0; other.inventory[i]; i++)
		inventory[i] = other.inventory[i];
	index = other.index;
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for(int i = 0; other.inventory[i]; i++)
			inventory[i] = other.inventory[i];
	}
	index = other.index;
	std::cout << "MateriaSource copy assignment operator called." << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < index; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
	std::cout << "MateriaSource destructor called." << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (index > 3)
		std::cout << "No room left to learn Materia." << std::endl;
	inventory[index] = m;
	std::cout << m->getType() << " has been learnt." << std::endl;
	index++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0;  i < index; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return (inventory[i]->clone()); // avec clone();
	}
	return (NULL);
}
