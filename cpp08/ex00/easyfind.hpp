#pragma once

# include <iostream>
# include <exception>
# include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator	easyfind(T& container, int	toFind)
{
	typename T::iterator	it;

	if (container.size() == 0)
		throw std::invalid_argument("Container is empty.");
	it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::invalid_argument("No occurence was found.");
	return (it);
}
