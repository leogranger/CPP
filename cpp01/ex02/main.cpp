#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory adress of string is: " << &string << std::endl;
	std::cout << "Memory adress of stringPTR is: " << stringPTR << std::endl;
	std::cout << "Memory adress of stringREF is: " << &stringREF << std::endl;

	std::cout << "Value of string is: " << string << std::endl;
	std::cout << "Value of stringPTR is: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF is: " << stringREF << std::endl;
}
