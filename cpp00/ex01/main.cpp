#include "PhoneBook.hpp"

Contact	createNewContact()
{
	Contact		contact;
	std::string	line;

	std::cout << "Type the first name of your new contact: " << std::endl;
	std::getline(std::cin, line);
	contact.setFirstName(line);
	std::cout << "Type the last name of your new contact: " << std::endl;
	std::getline(std::cin, line);
	contact.setLastName(line);
	std::cout << "Type the nickname of your new contact: " << std::endl;
	std::getline(std::cin, line);
	contact.setNickName(line);
	std::cout << "Type the phone number of your new contact: " << std::endl;
	std::getline(std::cin, line);
	contact.setPhoneNumber(line);
	std::cout << "Type a short secret about your new contact: " << std::endl;
	std::getline(std::cin, line);
	contact.setDarkestSecret(line);
	return (contact);
}

int	main(void)
{
	std::string	line;
	Contact		contact;
	PhoneBook	phonebook;

	while (!std::cin.eof())
	{
		std::cout << "Type your command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, line);
		if (line == "EXIT")
			break ;
		else if (line == "ADD")
		{
			contact = createNewContact();
			phonebook.addContact(contact);
		}
		else if (line == "SEARCH")
		{
			phonebook.searchContact();
		}
		else {
			std::cout << "Your command is invalid, try ADD, SEARCH or EXIT." << std::endl;
		}
	}
}