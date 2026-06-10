#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n===== CONSTRUCTOR TEST =====\n" << std::endl;

    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    std::cout << "\n===== ATTACK TEST =====\n" << std::endl;

    a.attack("Beta");
    b.takeDamage(0); // replace 0 with your attack damage if needed

    std::cout << "\n===== DAMAGE TEST =====\n" << std::endl;

    b.takeDamage(5);
    b.takeDamage(3);

    std::cout << "\n===== REPAIR TEST =====\n" << std::endl;

    b.beRepaired(4);

    std::cout << "\n===== COPY CONSTRUCTOR TEST =====\n" << std::endl;

    ClapTrap c(a);

    std::cout << "\n===== COPY ASSIGNMENT TEST =====\n" << std::endl;

    ClapTrap d("Temporary");
    d = b;

    std::cout << "\n===== ENERGY DEPLETION TEST =====\n" << std::endl;

    for (int i = 0; i < 11; i++)
        a.attack("training dummy");

    std::cout << "\n===== DEATH TEST =====\n" << std::endl;

    ClapTrap e("Fragile");

    e.takeDamage(100);
    e.attack("Nobody");
    e.beRepaired(10);

    std::cout << "\n===== OVERKILL TEST =====\n" << std::endl;

    ClapTrap f("Tank");

    f.takeDamage(5);
    f.takeDamage(1000);

    std::cout << "\n===== REPAIR UNTIL NO ENERGY =====\n" << std::endl;

    ClapTrap g("Mechanic");

    for (int i = 0; i < 12; i++)
        g.beRepaired(1);

    std::cout << "\n===== END OF PROGRAM =====\n" << std::endl;

    return (0);
}