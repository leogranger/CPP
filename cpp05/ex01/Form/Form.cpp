#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
	:_name("Default name")
	,_signed(false)
	,_signGrade(150)
	,_execGrade(150)
{
	std::cout << "Form default constructor called." << std::endl;
}
Form::Form(std::string name, const int signGrade, const int execGrade)
	:_name(name)
	,_signed(false)
	,_signGrade(signGrade)
	,_execGrade(execGrade)
{
	std::cout << "Form constructor called." << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	:_name(other._name)
	,_signed(other._signed)
	,_signGrade(other._signGrade)
	,_execGrade(other._execGrade)
{
	std::cout << "Form copy constructor called." << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called." << std::endl;
}

Form&		Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_signed = other._signed;
		this->_signGrade = other._signGrade;
		this->_execGrade = other._execGrade;
	}
	std::cout << "Form copy assignment operator called." << std::endl;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool		Form::getisSigned(void) const
{
	return (_signed);
}

int	Form::getsignGrade(void) const
{
	return (_signGrade);
}

int	Form::getexecGrade(void) const
{
	return (_execGrade);
}

void		Form::beSigned(Bureaucrat &boss)
{
	if (_signed)
		return ;
	if (boss.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " signed status: " << form.getisSigned()
		<< ", grade required to sign: " << form.getsignGrade()
		<< ", grade required to execute: " << form.getexecGrade();
	return (out);
}
