#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type)
	: _type(type)
	, _name(name)
{
	std::cout << "HumanA full constructor called." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor called." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << _name + " attacks with their " + _type.getType() << std::endl;
}