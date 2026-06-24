#include "Character.hpp"

Character::Character(void)
	: _name("")
	, index(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string name)
	: _name(name)
	, index(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Character constructor called." << std::endl;
}

Character::Character(const Character& other)
{
	_name = other._name;
	for (int i = 0; i < other.index; i++)
	{
		inventory[i] = other.inventory[i]->clone();
	}
	index = other.index;
	std::cout << "Character copy constructor called." << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = 0;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = 0;
		}
		this->index = other.index;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < index; i++)
	{
		delete inventory[i];
		inventory[i] = 0;
	}
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
			<< m->getType() << "." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Index out of inventory." << std::endl;
		return ;
	}
	std::cout << _name << " unequipped " << inventory[idx]->getType() << "." << std::endl;
	delete inventory[idx];
	inventory[idx] = 0;
	index--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || !inventory[idx])
	{
		std::cout << "You can't call this index, it should be between 0 and 3 and contain a Materia." << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}
