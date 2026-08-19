#include "Array.hpp"

template<typename T>
Array<T>::Array(void)
{
	this->_array = NULL;
	this->_size = 0;
	std::cout << "Array default constructor called." << std::endl;
}

template<typename T>
Array<T>::Array(int n)
{
	if (n < 0)
		throw std::invalid_argument("Index out of bounds.");
	this->_array = new T[n]();
	this->_size = n;
	std::cout << "Array constructor called." << std::endl;
}

template<typename T>
Array<T>::Array(const Array &other)
{
	this->_array = new T[other._size];
	for (int i = 0; i < other._size; i++)
		this->_array[i] = other._array[i];
	this->_size = other._size;
	std::cout << "Array copy constructor called." << std::endl;
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _array;
		this->_array = new T[other._size]();
		for (int i = 0; i < other._size; i++)
			this->_array[i] = other._array[i];
		this->_size = other._size;
	}
	std::cout << "Array copy assignment operator called." << std::endl;
	return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_array;
	std::cout << "Array destructor called." << std::endl;
}

template<typename T>
T&	Array<T>::operator[](int n)
{
	if (n >= this->_size || n < 0)
		throw std::invalid_argument("Index out of bounds.");
	return (this->_array[n]);
}

template<typename T>
const T&	Array<T>::operator[](int n) const
{
	if (n >= this->_size || n < 0)
		throw std::invalid_argument("Index out of bounds.");
	return (this->array[n]);
}

template<typename T>
unsigned int	Array<T>::size(void)
{
	return (static_cast<unsigned int>(this->_size));
}
