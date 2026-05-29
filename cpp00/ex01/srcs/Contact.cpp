#include "PhoneBook.hpp"

std::string	Contact::getFirstName(void) const
{
	return (_firstname);
}

std::string	Contact::getLastName(void) const
{
	return (_lastname);
}

std::string	Contact::getNickName(void) const
{
	return (_nickname);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkest_secret);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (_phone_number);
}

void		Contact::setFirstName(std::string name)
{
	_firstname = name;
}

void		Contact::setLastName(std::string name)
{
	_lastname = name;
}

void		Contact::setNickName(std::string name)
{
	_nickname = name;
}

void		Contact::setDarkestSecret(std::string secret)
{
	_darkest_secret = secret;
}

void		Contact::setPhoneNumber(std::string number)
{
	_phone_number = number;
}
