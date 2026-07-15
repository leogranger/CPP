#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:_name("Default name")
	,_grade(150)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:_name(name)
	,_grade(grade)
{
	std::cout << "Bureaucrat constructor called." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	:_name(other._name)
	,_grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void		Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
	{
		throw GradeTooHighException();
		return ;
	}
	_grade--;
}

void		Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
	{
		throw GradeTooLowException();
		return ;
	}
	_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name
				<< " couldn't sign "
				<< form.getName()
				<< " because "
				<< e.what()
				<< std::endl;
	}
}
