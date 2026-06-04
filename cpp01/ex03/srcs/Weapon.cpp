#include "Weapon.hpp"

Weapon::Weapon(void) : _type("")
{
	std::cout << _type + " was created." << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << _type + " was created." << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << _type << " was destroyed." << std::endl;
}

std::string	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	std::cout << this->_type + " was dropped." << std::endl;
	std::cout << type + " was picked up." << std::endl;
	this->_type = type;
}
