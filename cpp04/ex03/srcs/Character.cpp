#include "Character.hpp"

Character::Character(void)
	: _name("")
	, index(0)
{
	std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string name)
	: _name(name)
	, index(0)
{
	std::cout << "Character constructor called." << std::endl;
}

Character::Character(const Character& other)
{
	_name = other._name;
	for (int i = 0; i <= other.index; i++)
	{
		inventory[i] = other.inventory[i];
	}
	index = other.index;
	std::cout << "Character copy constructor called." << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i <= other.index; i++)
		{
			inventory[i] = other.inventory[i];
		}
		index = other.index;
	}
	std::cout << "Character copy assignment operator called." << std::endl;
}

Character::~Character()
{
	for (int i = 0; i <= index; i++)
		delete inventory[i];
	std::cout << "Character destructor called." << std::endl;
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (index > 3)
	{
		std::cout << _name << " can't store more AMateria, he needs to drop one."
				<< std::endl;
		return ;
	}
	inventory[index] = m;
	index++;
	std::cout << _name << " equipped "
			<< m->getType() << ".";
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Index out of inventory." << std::endl;
		return ;
	}
	std::cout << _name << "unequipped " << inventory[idx]->getType() << "." << std::endl;
	index--;
}

void Character::use(int idx, Character& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Index out of inventory." << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}
