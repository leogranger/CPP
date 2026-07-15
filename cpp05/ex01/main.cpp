#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n========== Bureaucrat constructor ==========\n";

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat employee("Employee", 75);
		Bureaucrat intern("Intern", 150);

		std::cout << boss << std::endl;
		std::cout << employee << std::endl;
		std::cout << intern << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Invalid Bureaucrats ==========\n";

	try
	{
		Bureaucrat high("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Form constructor ==========\n";

	try
	{
		Form tax("Tax Form", 50, 25);
		std::cout << tax << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Invalid Forms ==========\n";

	try
	{
		Form bad1("Bad1", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form bad2("Bad2", 10, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Signing ==========\n";

	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 40);
	Bureaucrat worker("Worker", 120);

	Form contract("Contract", 50, 20);

	std::cout << contract << std::endl;

	worker.signForm(contract);     // should fail
	std::cout << contract << std::endl;

	manager.signForm(contract);    // should succeed
	std::cout << contract << std::endl;

	boss.signForm(contract);       // already signed (depends on implementation)
	std::cout << contract << std::endl;

	std::cout << "\n========== Direct beSigned() ==========\n";

	Form permit("Permit", 10, 5);

	try
	{
		permit.beSigned(worker);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		permit.beSigned(boss);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e)
	{
	std::cout << e.what() << std::endl;
	}

	return (0);
}
