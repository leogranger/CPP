#pragma once

# include "Bureaucrat.hpp"
# include "AForm/AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern&	operator=(const Intern& other);
		~Intern(void);
		AForm*	makeForm(std::string formName, std::string formTarget);

		class FormIsNotRealException : public std::exception
		{
			virtual const char*	what() const throw(){
				return ("That form name doesn't exist.");
			}
		};
};