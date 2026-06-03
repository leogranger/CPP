#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::Zombie(void) : _name("") {}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " was destroyed." << std::endl;
}


void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
