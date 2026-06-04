#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public :
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &type);
		void	attack(void);
	private :
		Weapon		*_type;
		std::string	_name;
};

#endif