#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria*	inventory[4];
	public:
		Character(void);
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, Character& target);
		int	index;
};

#endif