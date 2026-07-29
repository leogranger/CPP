#include "PmergeMe.hpp"
#include <vector>

PMergeMe::PMergeMe(void)
{
	//std::cout << "PMergeMe constructor called." << std::endl;
}

PMergeMe::~PMergeMe(void)
{
	//std::cout << "PMergeMe destructor called." << std::endl;
}

PMergeMe::PMergeMe(const PMergeMe& other)
	:_PVector(other._PVector)
	,_PDeque(other._PDeque)
{
	//std::cout << "PMergeMe copy constructor called." << std::endl;
}

PMergeMe&	PMergeMe::operator=(const PMergeMe& other)
{
	if (this != &other)
	{
		_PVector = other._PVector;
		_PDeque = other._PDeque;
	}
	//std::cout << "PMergeMe copy assignment operator called." << std::endl;
	return (*this);
}

std::vector<long>	PMergeMe::getVector(void) const
{
	return (this->_PVector);
}

std::deque<long>	PMergeMe::getDeque(void) const
{
	return (this->_PDeque);
}

void	PMergeMe::checkNumbers(char **av) const
{
	for (int i = 1; av[i]; i++)
	{
		if (!isdigit(*av[i]))
		{
			throw std::invalid_argument("The input should only contain numbers.");
		}
	}
}

void	PMergeMe::fillVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		long nb = strtol(av[i], NULL, 10);
		if (errno == ERANGE || nb > INT_MAX || nb < 0)
			throw std::invalid_argument("Error: a number is out of range.");
		this->_PVector.push_back(nb);
	}
}

void	PMergeMe::fillDeque(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		long nb = strtol(av[i], NULL, 10);
		if (errno == ERANGE || nb > INT_MAX || nb < 0)
			throw std::invalid_argument("Error: a number is out of range.");
		this->_PDeque.push_back(nb);
	}
}

void	swapByPair(std::vector<long>& vec, size_t lvl)
{
	size_t	cmp = lvl - 1;
	while (lvl * 2 - 1 <= vec.size())
	{
		if (vec[cmp] > vec[lvl * 2 - 1])
			std::swap_ranges(vec.begin() + cmp, vec.begin() + cmp + lvl - 1, vec.begin() + lvl);
		cmp += lvl * 2;
	}
}

void	FordJohnsonVector(std::vector<long>& vec, size_t lvl)
{
	if (lvl > vec.size() / 2)
		return ;
	swapByPair(vec, lvl);
	std::cout << "Before: ";
	for (int i = 0; vec[i]; i++)
		std::cout << vec[i];
	std::cout << std::endl;
	FordJohnsonVector(vec, lvl * 2);
	return ;
}

void	PMergeMe::sortVector(void)
{
	prepContainer<std::vector<long> >(this->_PVector);
	FordJohnsonVector( _PVector, 2);
	return ;
}

void	PMergeMe::sortDeque(void)
{
	prepContainer(this->_PDeque);
}



/*
swapByPair:
je compare i = + lvl - 1 avec lvl += lvl -1 (avec un check si i+lvl <= container.size())
swap : swap_ranges(vec.begin() + i, vec.begin() + i + lvl - 1, vec.begin() + lvl, vec.begin() + lvl * 2 - 1);
ensuite i+=lvl*2

*/