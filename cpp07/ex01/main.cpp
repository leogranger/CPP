#include "iter.hpp"

void	printArr(int n)
{
	std::cout << n << std::endl;
}

void toUpper(char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	std::cout << c;
}

int	main(void)
{
	int intArr[5] = {1, 2, 3, 4, 5};
	iter(intArr, 5, printArr);
	char	str[6] = "hello";
	iter(str, 6, toUpper);
	return (0);
}