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
	line = enterInfo("Type the index of the contact you would like to display: ");
	if (checkLine(line))
	{
		int i = std::atoi(line.c_str());
		if (i >=0 && i <= std::min(_index, 8) - 1)
			printContact(contacts[i]);
		else
		{
			std::cout << "Wrong number." << std::endl;
			return ;
		}
	}
}
