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
	size_t p = 0;
	for(size_t i = 0; i < src.size(); i++)
	{
		while (i < start && src[i])
		{
			main.push_back(src[i]);
			i++;
		}
		if (p % 2 == 0)
		{
			for (size_t j = 0; j < lvl && i < src.size(); j++)
			{
				pend.push_back(src[i]);
				i++;
			}
		}
		else
		{
			for (size_t j = 0; j < lvl && i < src.size(); j++)
			{
				main.push_back(src[i]);
				i++;
			}
		}
		p++;
	}
}

size_t	binarySearchInsertPos(std::vector<long>& res, long value, size_t upperBound, size_t lvl)
{
	size_t low = 0;
	size_t high = upperBound;

	while (low < high)
	{
		size_t	mid = low + (high - low) / 2;
		long	midVal = res[mid * lvl + (lvl - 1)];

		if (midVal < value)
			low = mid + 1;
		else
			high = mid;
	}
	return (low * lvl);	//to get the right group index when lvl > 1
}

void	FordJohnsonVector(std::vector<long>& vec, size_t lvl)
{
	//swap
	if (lvl <= vec.size() / 2)
	{
		swapByPair(vec, lvl);
		FordJohnsonVector(vec, lvl * 2);
	}

	std::cout << "LEVEL: " << lvl << std::endl;
	// create and fill pend and long
	std::vector<long>	pend;
	std::vector<long>	main;
	pushPendAndMain(vec, pend, main, lvl);
	std::cout << "Pend: ";
	for (size_t i = 0; i < pend.size(); i++)
			std::cout << pend[i] << " ";
	std::cout << std::endl;
	std::cout << "Main: ";
	for (size_t i = 0; i < main.size(); i++)
			std::cout << main[i] << " ";
	std::cout << std::endl;
	size_t pendGroups = pend.size() / lvl;
	if (pendGroups == 0)
		return ;

	//find order in which pend has to be inserted (with indexes of pend)
	std::vector<long>	order;
	size_t				prev = 1;
	size_t				jac = 3;
	while (prev < pendGroups)
	{
		size_t stop;
		if (jac < pendGroups)
			stop = jac;
		else
			stop = pendGroups;
		for(size_t i = stop; i > prev; i--)
			order.push_back(i - 1);
		size_t next = jac + 2 * prev;
		prev = jac;
		jac = next;
	}

	//prep res with smallest number at the start
	std::vector<long>	res;
	res.insert(res.end(), pend.begin(), pend.begin() + lvl);
	res.insert(res.end(), main.begin(), main.end());

	//partner of the pend elements to then get the upperbound to binary search
	std::vector<size_t>	partner(pendGroups);
	for(size_t i = 0; i < pendGroups; i++)
		partner[i] = i;

	//insert following the order we founded before
	for(size_t i = 0; i < order.size(); i++)
	{
		size_t	group = order[i];
		long	value = pend[group * lvl + (lvl - 1)];
		size_t	upperBound = partner[group];
		size_t	pos = binarySearchInsertPos(res, value, upperBound, lvl);
		size_t	insertGroup = pos / lvl;

		res.insert(res.begin() + pos,
					pend.begin() + group * lvl,
					pend.begin() + group * lvl + lvl);
		// std::cout << "after insert: ";
		// for (size_t i = 0; i < res.size(); i++)
		// 	std::cout << res[i] << " ";
		// std::cout << std::endl;

		
		//shift the bigger partner by 1 because we just inserted a group
		for(size_t j = 0; j < pendGroups; j++)
		{
			if (partner[j] >= insertGroup)
				partner[j]++;
		}
	}
	vec = res;
	return ;
}

void	PMergeMe::sortVector(void)
{
	if (prepContainer<std::vector<long> >(this->_PVector))
		return ;
	FordJohnsonVector( _PVector, 1);
	std::cout << "After: ";
	for (size_t i = 0; i < _PVector.size(); i++)
		std::cout << _PVector[i] << " ";
	std::cout << std::endl;
	return ;
}

void	PMergeMe::sortDeque(void)
{
	prepContainer(this->_PDeque);
}

