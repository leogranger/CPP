#include "FragTrap.hpp"

int main(void)
{
	std::cout << "\n=== Constructor Test ===\n" << std::endl;

	FragTrap frag1("Fraggy");

	std::cout << "\n=== Basic Actions ===\n" << std::endl;

	frag1.attack("Bandit");
	frag1.takeDamage(25);
	frag1.beRepaired(10);
	frag1.highFivesGuys();

	std::cout << "\n=== Copy Constructor Test ===\n" << std::endl;

	FragTrap frag2(frag1);
	frag2.attack("CopyTarget");

	std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;

	FragTrap frag3("AnotherFrag");
	frag3 = frag1;
	frag3.highFivesGuys();

	std::cout << "\n=== Damage Test ===\n" << std::endl;

	frag1.takeDamage(200);
	frag1.attack("Nobody");
	frag1.beRepaired(10);
	frag1.highFivesGuys();

	std::cout << "\n=== End of Program ===\n" << std::endl;

	return (0);
}