#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
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

void	PMergeMe::sortVector(void)
{
	if (prepContainer<std::vector<long> >(this->_PVector))
		return ;
	FordJohnsonVector<std::vector<long> >( _PVector, 1);
	std::cout << "After: ";
	for (size_t i = 0; i < _PVector.size(); i++)
		std::cout << _PVector[i] << " ";
	std::cout << std::endl;
	return ;
}

void	PMergeMe::sortDeque(void)
{
	if (prepContainer<std::deque<long> >(this->_PDeque))
		return ;
	FordJohnsonVector<std::deque<long> >( _PDeque, 1);
	std::cout << "After: ";
	for (size_t i = 0; i < _PDeque.size(); i++)
		std::cout << _PDeque[i] << " ";
	std::cout << std::endl;
	return ;
}

