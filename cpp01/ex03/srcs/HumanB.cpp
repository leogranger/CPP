#include "HumanB.hpp"

HumanB::HumanB(void)
	: _type(NULL)
	, _name("defaultName")
{
	std::cout << "HumanB default constructor called." << std::endl;
}

HumanB::HumanB(std::string name)
	: _type(NULL)
	, _name(name)
{
	std::cout << "HumanB full constructor called." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destructor called." << std::endl;
}

void	HumanB::attack(void)
{
	if (_type == NULL)
	{
		std::cout << "No weapon was set." << std::endl;
		return ;
	}
	std::cout << _name + " attacks with their " << _type->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_type = &type;
}