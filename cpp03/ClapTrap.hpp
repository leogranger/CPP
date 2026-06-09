#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int		_Health;
		int		_energyPoints;
		int		_attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name, int health, int energy, int attack);
		ClapTrap(const ClapTrap& other);
		~ClapTrap(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif