#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("")
	, _Health(0)
	, _energyPoints(0)
	, _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name)
	, _Health(10)
	, _energyPoints(10)
	, _attackDamage(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name, int health, int energy, int attack)
	: _name(name)
	, _Health(health)
	, _energyPoints(energy)
	, _attackDamage(attack)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name)
	, _Health(other._Health)
	, _energyPoints(other._energyPoints)
	, _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called." << std::endl;

	if (this != &other)
	{
		_name = other._name;
		_Health = other._Health;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_Health == 0)
	{
		std::cout << _name << " is dead and can't attack..." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "You have no energy points ! Repair yourself before attacking." << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_Health == 0)
	{
		std::cout << _name << " is already dead, why would you even do that ?? You're a psychopath." << std::endl;
		return ;
	}
	else if (_Health <= amount)
	{
		_Health = 0;
		std::cout << _name << " takes damage, causing "
		<< amount << " points of damage!" << std::endl;
		std::cout << _name << " has died :(" << std::endl;
		return ;
	}
	_Health -= amount;
	std::cout << _name << " takes damage, causing "
		<< amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_Health == 0)
	{
		std::cout << _name << " is dead and can't be repaired..." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "You have no energy points ! You might die if this keeps goind :(" << std::endl;
		return ;
	}
	_Health += amount;
	_energyPoints -= 1;
	std::cout << _name << " is repaired with " << amount << " its health is now at: " << _Health << std::endl;
}
