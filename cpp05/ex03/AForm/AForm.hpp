#pragma once

# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	public:

		AForm(void);
		AForm(std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		virtual ~AForm(void);
		AForm&				operator=(const AForm& other);
		std::string			getName(void) const;
		bool				getisSigned(void) const;
		int					getsignGrade(void) const;
		int					getexecGrade(void) const;
		void				beSigned(Bureaucrat &boss);
		virtual void		execute(Bureaucrat const & executor) const;

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
		class FormNotSignedException: public std::exception
		{
			virtual const char* what() const throw(){
				return ("Form not signed.");
			}
		};
	
	private:
		std::string	_name;
		bool		_signed;
		int			_signGrade;
		int			_execGrade;
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);