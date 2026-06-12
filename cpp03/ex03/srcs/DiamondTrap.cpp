#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap()
	, ScavTrap()
	, FragTrap()
	, name("default")
{
	_Health = 100;
	_energyPoints = 50;
	_attackDamage = 30;

	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
	, ScavTrap(name)
	, FragTrap(name)
	, name(name)
{
	_Health = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other)
	, ScavTrap(other)
	, FragTrap(other)
	, name(other.name)
{
	std::cout  << "DiamondTrap copy constructor called." << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	std::cout  << "DiamondTrap copy assignment operator called." << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	if (_Health == 0)
	{
		std::cout << name << " is dead so obviously it can't say its name, can it?" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << name << " has not enough energy to remember who he is, please repair him." << std::endl;
		return ;
	}
	std::cout << "I am " << name
		<< ", but my shadow name is "
		<< _name << "." << std::endl;
}
