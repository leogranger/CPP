#include "PhoneBook.hpp"

std::string	enterInfo(std::string print)
{
	std::string	line;

	while (!std::cin.eof())
	{
		std::cout << print;
		std::getline(std::cin, line);
		if (isalnum(line[0]))
			break ;
	}
	return (line);
}

Contact	createNewContact()
{
	Contact		contact;
	std::string	line;

	line = enterInfo("Type the first name of your new contact: ");
	contact.setFirstName(line);
	line = enterInfo("Type the last name of your new contact: ");
	contact.setLastName(line);
	line = enterInfo("Type the nickname of your new contact: ");
	contact.setNickName(line);
	line = enterInfo("Type the phone number of your new contact: ");
	contact.setPhoneNumber(line);
	line = enterInfo("Type a short secret about your new contact: ");
	contact.setDarkestSecret(line);
	return (contact);
}

void	printPhoneBook(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << str << "|";
}

void	printContact(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nick name: " << contact.getNickName() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
}

int	checkLine(std::string line)
{
	for (unsigned long int i = 0; i < line.length(); i++)
	{
		if (std::isdigit(line[i]))
			continue ;
		else
		{
			std::cout << "Only numbers between 0 and 7 are accepted." << std::endl;
			return(0);
		}
	}
	return (1);
}