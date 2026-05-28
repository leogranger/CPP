#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>

class Contact
{
	public:
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getDarkestSecret(void) const;
		std::string	getPhoneNumber(void) const;
		void		setFirstName(std::string name);
		void		setLastName(std::string name);
		void		setNickName(std::string name);
		void		setDarkestSecret(std::string secret);
		void		setPhoneNumber(std::string number);
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_darkest_secret;
		std::string	_phone_number;
};

class PhoneBook
{
	public:
		PhoneBook(void);
		void	addContact(Contact contact);
		void	searchContact(void);
	private:
		Contact	contacts[8];
		int		_index;
};

#endif