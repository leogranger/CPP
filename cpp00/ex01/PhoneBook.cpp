#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

void	PhoneBook::addContact(Contact contact)
{
	contacts[_index % 8] = contact;
	_index++;
}

void	printPhoneBook(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << str << "|";
}

void	printContact(Contact contact)
{
	std::cout << "First name :" << contact.getFirstName() << std::endl;
	std::cout << "Last name :" << contact.getLastName() << std::endl;
	std::cout << "Nick name :" << contact.getNickName() << std::endl;
	std::cout << "Darkest secret :" << contact.getDarkestSecret() << std::endl;
	std::cout << "Phone number :" << contact.getPhoneNumber() << std::endl;
}

int	check_line(std::string line)
{
	for (int i = 0; i < line.length(); i++)
	{
		if (std::isdigit(line[i]))
			continue ;
		else
			return(0);
	}
	return (1);
}

void	PhoneBook::searchContact(void)
{
	std::string	line;

	for (int i = 0; i < std::min(_index, 8); i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		printPhoneBook(contacts[i].getFirstName());
		printPhoneBook(contacts[i].getLastName());
		printPhoneBook(contacts[i].getNickName());
		std::cout << std::endl;
	}
	std::cout << "Type the index of the contact you would like to display: " << std::endl;
	std::getline(std::cin, line);
	if (check_line(line))
	{
		int i = std::atoi(line.c_str());
		if (i >=0 && i <= std::min(_index, 8) - 1)
			printContact(contacts[i]);
		else
		{
			std::cout << "It has to be a number between 0 and 7." << std::endl;
			return ;
		}
	}
}
