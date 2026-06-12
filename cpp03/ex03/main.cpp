#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n===== CONSTRUCTOR TEST =====\n" << std::endl;

    DiamondTrap a("Diamond");

    std::cout << "\n===== WHO AM I =====\n" << std::endl;

    a.whoAmI();

    std::cout << "\n===== ATTACK TEST =====\n" << std::endl;

    a.attack("Bandit");

    std::cout << "\n===== REPAIR / DAMAGE TEST =====\n" << std::endl;

    a.takeDamage(20);
    a.beRepaired(10);

    std::cout << "\n===== SCAVTRAP ABILITY =====\n" << std::endl;

    a.guardGate();

    std::cout << "\n===== FRAGTRAP ABILITY =====\n" << std::endl;

    a.highFivesGuys();

    std::cout << "\n===== COPY CONSTRUCTOR =====\n" << std::endl;

    DiamondTrap b(a);
    b.whoAmI();

    std::cout << "\n===== ASSIGNMENT OPERATOR =====\n" << std::endl;

    DiamondTrap c("Other");
    c = a;
    c.whoAmI();

    std::cout << "\n===== DESTRUCTION TEST =====\n" << std::endl;

    return (0);
}
