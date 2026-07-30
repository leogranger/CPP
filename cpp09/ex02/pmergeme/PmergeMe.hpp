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
		for (int i = 0; container[i]; i++)
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

};
