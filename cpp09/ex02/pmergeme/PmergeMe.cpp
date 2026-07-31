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

void	swapByPair(std::vector<long>& vec, size_t lvl)
{
	size_t index = lvl - 1;

	while (index + lvl < vec.size())
	{
		if (vec[index] > vec[index + lvl])
		{
			size_t left = index + 1 - lvl;
			std::swap_ranges(vec.begin() + left, vec.begin() + left + lvl, vec.begin() + left + lvl);
		}
		index += lvl * 2;
	}
}

void	pushPendAndMain(std::vector<long>& src, std::vector<long>& pend, std::vector<long>& main, size_t lvl)
{
	size_t	start = lvl * 2;
	for(size_t i = 0; i < src.size(); i++)
	{
		size_t p = 0;
		while (i < start && src[i])
		{
			main.push_back(src[i]);
			i++;
		}
		if (p % 2 == 0)
		{
			for (size_t j = 0; j < lvl && src[i]; j++)
			{
				pend.push_back(src[i]);
				i++;
			}
		}
		else
		{
			for (size_t j = 0; j < lvl && src[i]; j++)
			{
				main.push_back(src[i]);
				i++;
			}
		}
		p++;
	}
}

void	FordJohnsonVector(std::vector<long>& vec, size_t lvl)
{
	//swap
	if (lvl <= vec.size() / 2)
	{
		swapByPair(vec, lvl);
		FordJohnsonVector(vec, lvl * 2);
	}

	// create and fill pend and long
	std::vector<long>	pend;
	std::vector<long>	main;
	pushPendAndMain(vec, pend, main, lvl);
	if (lvl > pend.size() - 1)
		return ;

	//find order in which pend has to be inserted (with indexes of pend)
	std::vector<long>	order;
	size_t				prev = 1;
	size_t				jac = 3;
	while (prev < pend.size())
	{
		size_t stop;
		if (jac < pend.size())
			stop = jac;
		else
			stop = pend.size();
		for(size_t i = stop; i > prev; i--)
			order.push_back(i - 1);
		size_t next = jac + 2 * prev;
		prev = jac;
		jac = next;
	}

	//prep res with smallest number at the start
	std::vector<long>	res;
	res.push_back(pend[0]);
	for(size_t i = 0; i < main.size(); i++)
		res.push_back(main[i]);

	//insert following the order we founded before
	


	return ;
}

void	PMergeMe::sortVector(void)
{
	if (prepContainer<std::vector<long> >(this->_PVector))
		return ;
	FordJohnsonVector( _PVector, 1);
	// std::cout << "After: ";
	// for (size_t i = 0; i < _PVector.size(); i++)
	// 	std::cout << _PVector[i] << " ";
	// std::cout << std::endl;
	return ;
}

void	PMergeMe::sortDeque(void)
{
	prepContainer(this->_PDeque);
}

/*
fordJohnson:
swap: done.
vector pend = b2, b3,...,bn -> include lvl elements / 2 after skipping lvl * 2 elements
vector main = b1, a1, a2,...,an
*/