#pragma once

# include <iostream>
# include <exception>
# include <fstream>
# include <string>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat &other);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(AForm &form);
		void		executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception
		{
			virtual const char*	what() const throw(){
				return ("Grade too high.");
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char*	what() const throw(){
				return ("Grade too low.");
			}
		};

	private:
		std::string _name;
		int			_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);