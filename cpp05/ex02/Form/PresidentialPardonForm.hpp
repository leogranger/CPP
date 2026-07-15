#pragma once

# include "AForm.hpp"

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
		void	bePardoned(void);
};