#pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void	createTree(void);
};