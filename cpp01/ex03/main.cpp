#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        std::cout << "===== HUMAN A =====\n";

        Weapon club("crude spiked club");

        HumanA bob("Bob", club);

        bob.attack();

        club.setType("some other type of club");

        bob.attack();
    }

    std::cout << '\n';

    {
        std::cout << "===== HUMAN B =====\n";

        Weapon club("crude spiked club");

        HumanB jim("Jim");

        jim.attack(); // should not crash

        jim.setWeapon(club);

        jim.attack();

        club.setType("some other type of club");

        jim.attack();
    }

    std::cout << '\n';

    {
        std::cout << "===== SHARED WEAPON =====\n";

        Weapon sword("sword");

        HumanA a("Arthur", sword);
        HumanB b("Lancelot");

        b.setWeapon(sword);

        a.attack();
        b.attack();

        sword.setType("legendary sword");

        a.attack();
        b.attack();
    }

    return 0;
}