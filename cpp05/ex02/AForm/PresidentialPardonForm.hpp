#pragma once

# include "AForm.hpp"
# include "../Bureaucrat/Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		void	execute(Bureaucrat const & executor) const;
};