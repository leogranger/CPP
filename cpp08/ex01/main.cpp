#include "Span/Span.hpp"

int main()
{
	std::cout << std::endl << "==== 10'000 NUMBERS TEST ====" << std::endl  << std::endl;
	try
	{
		Span sp(10000);
		std::vector<int>range;

		for (int i = 0; i < 10000; i++)
		{
			range.push_back(rand());
		}
		sp.addRange(range);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "==== NO SPAN POSSIBLE ====" << std::endl << std::endl;
	try
	{
		Span sp(5);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "==== VECTOR IS FULL ====" << std::endl << std::endl;
	try
	{
		Span sp(5);
		std::vector<int>range;

		for (int i = 0; i < 10; i++)
		{
			range.push_back(rand());
		}
		sp.addRange(range);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}