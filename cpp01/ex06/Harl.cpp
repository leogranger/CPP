#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl default constructor called." << std::endl;	
}

Harl::~Harl(void)
{
	std::cout << "Harl default destructor called." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon"
				" for my 7XL-double-cheese-triple-pickle-specialketchup"
				" burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon"
				" costs more money. You didn’t put"
				" enough bacon in my burger! If you did,"
				" I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
				" I’ve been coming for years, whereas you started working"
				" here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable!"
				" I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	lvl = 0;

	for (int i = 0; i < 4; i++)
	{
		if (comments[i] == level)
		{
			lvl = i;
			break ;
		}
	}
	switch (lvl)
	{
		case 0:
			&Harl::debug;
		case 1:
			&Harl::info;
		case 2:
			&Harl::warning;
		case 3:
			&Harl::error;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
