#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	_Health = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (_Health == 0)
	{
		std::cout << "I'd love to high five someone right now but i'm kinda dead..." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "I'm trying my best to hold my arm up to high five but i don't have any energy left in my body, do you think you can help me be repaired ?? Pleaaaaaaase!!" << std::endl;
		return ;
	}
	std::cout << "WHO WANTS A HIGH FIVE BABYYYYYY ?? COME ONE GUYS LETS HIGH FIVE! ITS GOOD FOR THE SPIRIT HAHAHA!!" << std::endl;
}