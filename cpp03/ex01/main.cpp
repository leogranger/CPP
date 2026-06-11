#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "==== CONSTRUCTOR TEST ====" << std::endl;
	ScavTrap a("Pablo");
	ScavTrap b("Pedro");

	std::cout << "==== BATTLE TEST ====" << std::endl;
	a.attack("Beta");
	b.takeDamage(0); // replace 0 with your attack damage if needed

	std::cout << "\n===== DAMAGE TEST =====\n" << std::endl;

	b.takeDamage(5);
	b.takeDamage(3);

	std::cout << "\n===== REPAIR TEST =====\n" << std::endl;

	b.beRepaired(4);

	std::cout << "\n===== ENERGY DEPLETION TEST =====\n" << std::endl;

	for (int i = 0; i < 11; i++)
		a.attack("training dummy");
	
	std::cout << "\n===== ENERGY DEPLETION TEST =====\n" << std::endl;

	for (int i = 0; i < 101; i++)
		a.attack("training dummy");

	std::cout << "\n===== DEATH TEST =====\n" << std::endl;

	ScavTrap e("Fragile");

	e.takeDamage(1000);
	e.attack("Nobody");
	e.beRepaired(10);

	std::cout << "\n===== OVERKILL TEST =====\n" << std::endl;

	ScavTrap f("Tank");

	f.takeDamage(5);
	f.takeDamage(1000);

	std::cout << "\n===== REPAIR =====\n" << std::endl;

	ScavTrap g("Mechanic");

	for (int i = 0; i < 12; i++)
		g.beRepaired(1);

	std::cout << "\n===== HOOOOOOOLD THE DOOOOOR =====\n" << std::endl;

	ScavTrap h("Hodor");
	h.guardGate();
	a.guardGate();
	f.guardGate();
}