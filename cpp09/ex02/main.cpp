#include "pmergeme/PmergeMe.hpp"
#include <sys/time.h>
#include <stdio.h>

double	getTimeDiff(struct timeval& start, struct timeval& end)
{
	return ((end.tv_usec - start.tv_usec) * 1e6);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "This program needs at least 2 numerical arguments." << std::endl;
		return (1);
	}
	try
	{
		PMergeMe merge;
		//struct timeval start;
		//struct timeval end;
		merge.checkNumbers(av);

		//gettimeofday(&start, NULL);
		merge.fillVector(ac, av);
		merge.sortVector();
		//gettimeofday(&end, NULL);
		//long	vtime = getTimeDiff(start, end);

		// gettimeofday(&start, NULL);
		// merge.fillDeque(ac, av);
		// merge.sortDeque();
		// gettimeofday(&end, NULL);
		// long	dtime = getTimeDiff(start, end);

		// std::cout << "Time to sort " << merge.getVector().size() << " numbers using a vector: "
		// 		<< vtime << " us" << std::endl;
		// std::cout << "Time to sort " << merge.getDeque().size() << " numbers using a deque: "
		// 		<< dtime << " us" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}