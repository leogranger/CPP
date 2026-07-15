#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	:AForm()
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequestForm", 72, 45)
	,_target(target)
{
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	std::cout << "RobotomyRequestForm copy assignment operator called." << std::endl;
	return (*this);
}

void	RobotomyRequestForm::Robotomise(void)
{
	std::cout << "DRILLING NOISE...VRRRRRRR..." << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << _target << " has been successfully robotomised." << std::endl;
	else
		std::cout << _target << "'s robotomy failed..." << std::endl;
}