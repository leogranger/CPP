#include "Bureaucrat.hpp"
#include "AForm/PresidentialPardonForm.hpp"
#include "AForm/ShrubberyCreationForm.hpp"
#include "AForm/RobotomyRequestForm.hpp"
#include "Intern/Intern.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	// Bureaucrat boss("Jim", 1);
	// Intern someRandomIntern;
	// AForm* rrf;

	// try
	// {
	// 	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	// 	boss.signForm(*rrf);
	// 	boss.executeForm(*rrf);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	Intern intern;

	std::cout << "\n========== SHRUBBERY ==========\n";
	try
	{
		Bureaucrat boss("Boss", 1);

		AForm *form = intern.makeForm("shrubbery creation", "home");

		boss.signForm(*form);
		boss.executeForm(*form);

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== ROBOTOMY ==========\n";
	try
	{
		Bureaucrat boss("Boss", 1);

		AForm *form = intern.makeForm("robotomy request", "Bender");

		boss.signForm(*form);

		for (int i = 0; i < 5; i++)
			boss.executeForm(*form);

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== PRESIDENTIAL ==========\n";
	try
	{
		Bureaucrat boss("Boss", 1);

		AForm *form = intern.makeForm("presidential pardon", "Arthur Dent");

		boss.signForm(*form);
		boss.executeForm(*form);

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID FORM ==========\n";
	try
	{
		AForm *form = intern.makeForm("coffee request", "me");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
