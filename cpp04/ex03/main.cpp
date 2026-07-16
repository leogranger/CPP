#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << "\n=== MateriaSource basic test ===\n";

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* tmp1 = src->createMateria("ice");
    AMateria* tmp2 = src->createMateria("cure");
    AMateria* tmp3 = src->createMateria("unknown"); // should return NULL

    std::cout << "tmp1: " << (tmp1 ? tmp1->getType() : "NULL") << std::endl;
    std::cout << "tmp2: " << (tmp2 ? tmp2->getType() : "NULL") << std::endl;
    std::cout << "tmp3: " << (tmp3 ? tmp3->getType() : "NULL") << std::endl;

    std::cout << "\n=== Character equip/use test ===\n";

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    me->equip(tmp1);
    me->equip(tmp2);

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob); // empty slot

    std::cout << "\n=== Inventory overflow test ===\n";

    me->equip(new Ice());
    me->equip(new Ice());
    me->equip(new Ice()); // should fail or be ignored

    std::cout << "\n=== Unequip test (VERY IMPORTANT) ===\n";

    me->unequip(1);
    delete tmp2;
    tmp2 = NULL;
    me->use(1, *bob); // should do nothing

    std::cout << "\n=== Memory ownership test ===\n";

    AMateria* leakTest = new Cure();
    me->equip(leakTest);

    me->unequip(1);
    delete leakTest; // should NOT double delete
    leakTest = NULL;

    me->unequip(0);
    delete tmp1;
    tmp1 = NULL;

    std::cout << "\n=== Deep copy test ===\n";

    Character original("original");

    original.equip(new Ice());
    original.equip(new Cure());

    Character copy(original);

    original.use(0, *bob);
    copy.use(0, *bob);

    std::cout << "\n=== Assignment operator test ===\n";

    Character assigned("assigned");

    assigned = original;

    assigned.use(0, *bob);
    assigned.use(1, *bob);

    std::cout << "\n=== MateriaSource cloning test ===\n";

    IMateriaSource* src2 = new MateriaSource(*dynamic_cast<MateriaSource*>(src));

    AMateria* clone1 = src2->createMateria("ice");
    AMateria* clone2 = src2->createMateria("cure");

    std::cout << clone1->getType() << std::endl;
    std::cout << clone2->getType() << std::endl;

    delete clone1;
    delete clone2;

    std::cout << "\n=== Cleanup ===\n";

    delete bob;
    delete me;
    delete src;
    delete src2;

    return 0;
}