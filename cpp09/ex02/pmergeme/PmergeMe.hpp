#pragma once

# include <iostream>
# include <deque>
# include <vector>
# include <exception>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <algorithm>

class PMergeMe
{
	private:
		std::vector<long>	_PVector;
		std::deque<long>	_PDeque;

	public:

	PMergeMe(void);
	~PMergeMe(void);
	PMergeMe(const PMergeMe& other);
	PMergeMe&operator=(const PMergeMe& other);
	std::vector<long>	getVector(void) const;
	std::deque<long>	getDeque(void) const;

	void	checkNumbers(char **av) const;
	void	fillVector(int ac, char **av);
	void	fillDeque(int ac, char **av);
	void	sortVector(void);
	void	sortDeque(void);

	template<typename T>
	bool	prepContainer(T& container)
	{
		std::cout << "Before: ";
		for (size_t i = 0; i < container.size(); i++)
			std::cout << container[i] << " ";
		std::cout << std::endl;
		size_t i = 0;
		while (i < container.size())
		{
			if (container[i + 1] && container[i] > container[i + 1])
					break ;
			i++;
		}
		if (i == container.size())
		{
			std::cout << "After: Sequence is already sorted." << std::endl;
			return true;
		}
		return false;
	}

	template<typename T>
	void	swapByPair(T& vec, size_t lvl)
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

	template<typename T>
	void	pushPendAndMain(T& src, T& pend, T& main, T& leftover, size_t lvl)
	{
		size_t p = 0;
		while (p + lvl * 2 < src.size())
		{
			for (size_t j = 0; j < lvl; j++)
				pend.push_back(src[p++]);
			for (size_t j = 0; j < lvl; j++)
				main.push_back(src[p++]);
		}
		while (p < src.size())
		{
			leftover.push_back(src[p++]);
		}
	}

	template<typename T>
	size_t	binarySearchInsertPos(T& res, long value, size_t upperBound, size_t lvl)
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

	template<typename T>
	void	handleLeftover(T& res, T& leftover, size_t lvl)
	{
		size_t lo = 0;
		while (lo + lvl <= leftover.size())
		{
			long	value = leftover[lo + lvl - 1];
			size_t	pos = binarySearchInsertPos(res, value, res.size() / lvl, lvl);

			res.insert(res.begin() + pos,
						leftover.begin() + lo,
						leftover.begin() + lo + lvl);
			lo += lvl;
		}
		while (lo < leftover.size())
		{
			if (lvl == 1)
			{
				size_t pos = binarySearchInsertPos(res, leftover[lo], res.size(), lvl);
				res.insert(res.begin() + pos, leftover[lo]);
			}
			else
				res.push_back(leftover[lo]);
			++lo;
		}
	}

	template<typename T>
	void	FordJohnsonVector(T& vec, size_t lvl)
	{
		//swap
		if (lvl * 2 <= vec.size())
		{
			swapByPair(vec, lvl);
			FordJohnsonVector(vec, lvl * 2);
		}

		// create and fill pend and long
		T	pend;
		T	main;
		T	leftover;
		pushPendAndMain(vec, pend, main, leftover, lvl);
		size_t pendGroups = pend.size() / lvl;
		if (pendGroups == 0)
			return ;

		//find order in which pend has to be inserted (with indexes of pend)
		T	order;
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
		T	res;
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

			//shift the bigger partner by 1 because we just inserted a group
			for(size_t j = 0; j < pendGroups; j++)
			{
				if (partner[j] >= insertGroup)
					partner[j]++;
			}
		}
		handleLeftover(res, leftover, lvl);
		vec.swap(res);
		return ;
	}

	};
