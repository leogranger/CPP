#include "whatever.hpp"

int	main(void)
{
	std::cout << "==== VALUE ASSIGNMENT ====" << std::endl;

	int	a = 3;
	int	b = 9;
	std::string s1 = "Hello";
	std::string s2 = "World";

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;

	std::cout << "==== SWAP ====" << std::endl;

	::swap(a, b);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	::swap(s1, s2);
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;

	std::cout << "==== MIN/MAX ====" << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
}