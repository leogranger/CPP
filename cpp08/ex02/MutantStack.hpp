#pragma once

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack(void);
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack(void);

		typedef typename MutantStack<T>::container_type::iterator iterator;

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"