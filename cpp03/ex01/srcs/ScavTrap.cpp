#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_Health = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout  << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_Health <= 0)
	{
		std::cout << "Why would you ask a dead guy to hold the door ?" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << _name << " is wayyyyyyyyy too tired, repair him or let him sleep." << std::endl;
		return ;
	}
	std::cout << _name << " is guarding the Gate with all his might. YOU SHALL NOT PASS!!" << std::endl;
}