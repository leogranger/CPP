#include "Cure.hpp"

Cure::Cure(void)
	: AMateria()
{
	_type = "cure";
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure& other)
	: AMateria(other)
{
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called." << std::endl;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals "
		<< target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}
