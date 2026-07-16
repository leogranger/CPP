#include "Bureaucrat.hpp"
#include "AForm/PresidentialPardonForm.hpp"
#include "AForm/ShrubberyCreationForm.hpp"
#include "AForm/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));
	// Bureaucrat	Boss("Jim", 1);
	// Bureaucrat	Employee("Pat", 50);
	// Bureaucrat	Worker("Kurt", 150);

	// PresidentialPardonForm	Pardon("James");
	// ShrubberyCreationForm	Tree("bigTree");
	// RobotomyRequestForm		Robot("Frank");

	// try
	// {
	// 	Pardon.beSigned(Boss);
	// 	Tree.beSigned(Boss);
	// 	Robot.beSigned(Boss);

	// 	Pardon.execute(Boss);
	// 	Tree.execute(Boss);
	// 	Robot.execute(Boss);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	std::cout << "========== SHRUBBERY ==========\n";
    try
    {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");

        std::cout << shrub << std::endl;

        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== ROBOTOMY ==========\n";
    try
    {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");

        alice.signForm(robot);

        // Execute several times to see both success and failure
        for (int i = 0; i < 5; i++)
            alice.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== PRESIDENTIAL ==========\n";
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== GRADE TOO LOW ==========\n";
    try
    {
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm shrub("garden");

        low.signForm(shrub);
        low.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== EXECUTE UNSIGNED ==========\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Marvin");

        // Never signed
        boss.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	Bureaucrat test("Test", 140);
	ShrubberyCreationForm form("tree");

	test.signForm(form);      // should succeed
	test.executeForm(form);   // should fail (needs 137)	

	return (0);
}
