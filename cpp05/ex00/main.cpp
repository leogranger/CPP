#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat low("Jack", 150);
	Bureaucrat high("Daniel", 1);

	std::cout << low << std::endl;
	low.incrementGrade();
	std::cout << low << std::endl;

	try
	{
		low.decrementGrade();
		std::cout << low << std::endl;
		high.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// std::cout << "===== Valid Bureaucrat =====" << std::endl;
    // try
    // {
    //     Bureaucrat bob("Bob", 42);
    //     std::cout << bob << std::endl;

    //     bob.incrementGrade();
    //     std::cout << "After increment: " << bob << std::endl;

    //     bob.decrementGrade();
    //     std::cout << "After decrement: " << bob << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n===== Grade Too High =====" << std::endl;
    // try
    // {
    //     Bureaucrat alice("Alice", 0);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n===== Grade Too Low =====" << std::endl;
    // try
    // {
    //     Bureaucrat john("John", 151);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n===== Increment Exception =====" << std::endl;
    // try
    // {
    //     Bureaucrat chief("Chief", 1);
    //     std::cout << chief << std::endl;
    //     chief.incrementGrade();
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "\n===== Decrement Exception =====" << std::endl;
    // try
    // {
    //     Bureaucrat intern("Intern", 150);
    //     std::cout << intern << std::endl;
    //     intern.decrementGrade();
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    return 0;
}
