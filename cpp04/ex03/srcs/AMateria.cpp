#include "AMateria.hpp"

AMateria::AMateria(void)
	: _type("")
{
	std::cout << "Amateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
	: _type(type)
{
	std::cout << "AMateria constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other)
	: _type(other._type)
{
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "AMateria copy assignment operator called." << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called." << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
} //Returns the materia type

void AMateria::use(ICharacter& target)
{
	std::cout << _type << "is used on " << target.getName() << "." << std::endl;
}
