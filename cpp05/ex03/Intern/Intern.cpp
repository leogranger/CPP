#include "Intern.hpp"
#include "AForm/RobotomyRequestForm.hpp"
#include "AForm/PresidentialPardonForm.hpp"
#include "AForm/ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called." << std::endl;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy assignment operator called." << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
}

AForm* createShruddery(std::string target) {return new ShrubberyCreationForm(target);}
AForm* createRobotomy(std::string target) {return new RobotomyRequestForm(target);}
AForm* createPardon(std::string target) {return new PresidentialPardonForm(target);}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm*	(*creators[3])(std::string) = {createRobotomy, createShruddery, createPardon};
	int			lvl = 3;

	for (int i = 0; i < lvl; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (creators[i](formTarget));
		}
	}
	throw FormIsNotRealException();
}
