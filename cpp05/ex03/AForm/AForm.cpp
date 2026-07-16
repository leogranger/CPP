#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
	:_name("Default name")
	,_signed(false)
	,_signGrade(150)
	,_execGrade(150)
{
	std::cout << "AForm default constructor called." << std::endl;
}
AForm::AForm(std::string name, const int signGrade, const int execGrade)
	:_name(name)
	,_signed(false)
	,_signGrade(signGrade)
	,_execGrade(execGrade)
{
	std::cout << "AForm constructor called." << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	:_name(other._name)
	,_signed(other._signed)
	,_signGrade(other._signGrade)
	,_execGrade(other._execGrade)
{
	std::cout << "AForm copy constructor called." << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called." << std::endl;
}

AForm&		AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_signed = other._signed;
		this->_signGrade = other._signGrade;
		this->_execGrade = other._execGrade;
	}
	std::cout << "AForm copy assignment operator called." << std::endl;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool		AForm::getisSigned(void) const
{
	return (_signed);
}

int	AForm::getsignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getexecGrade(void) const
{
	return (_execGrade);
}

void		AForm::beSigned(Bureaucrat &boss)
{
	if (_signed)
		return ;
	if (boss.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << " signed status: " << AForm.getisSigned()
		<< ", grade required to sign: " << AForm.getsignGrade()
		<< ", grade required to execute: " << AForm.getexecGrade();
	return (out);
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (!this->_signed)
		throw FormNotSignedException();
	std::cout << executor.getName()
			<< " executed " << _name
			<< std::endl;
}
