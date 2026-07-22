#pragma once
#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
	//std::cout << "MutantStack constructor called." << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
{
	(void)other;
	//std::cout << "MutantStack constructor called." << std::endl;
}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
	{
		return(*this);
	}
	return(*this);
	//std::cout << "MutantStack copy assignment operator called." << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	//std::cout << "MutantStack destructor called." << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return(this->c.end());
}
