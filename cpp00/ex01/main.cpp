#include "PhoneBook.hpp"

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
	}
}
