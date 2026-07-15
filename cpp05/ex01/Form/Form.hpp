#pragma once

# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, const int signGrade, const int execGrade);
		Form(const Form &other);
		~Form(void);
		Form&		operator=(const Form& other);
		std::string	getName(void) const;
		bool		getisSigned(void) const;
		int			getsignGrade(void) const;
		int			getexecGrade(void) const;
		void		beSigned(Bureaucrat &boss);
		class GradeTooHighException: public std::exception
		{
			virtual const char*	what() const throw(){
				return ("grade too high.");
			}
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char*	what() const throw(){
				return ("grade too low.");
			}
		};
	private:
		std::string	_name;
		bool		_signed;
		int			_signGrade;
		int			_execGrade;
};

std::ostream &operator<<(std::ostream &out, const Form &form);