#pragma once

# include <iostream>
# include <exception>

template<typename T>
class Array
{
	private:

		T*				_array;
		int	_size;


	public:

		Array(void);
		Array(int n);
		Array(const Array &other);
		Array&	operator=(const Array &other);
		~Array(void);

		T&				operator[](int n);
		const T&		operator[](int n) const;
		unsigned int	size(void);
};

#include "Array.tpp"

//throw std::invalid_argument("Index out of bounds.")
//instead of :
//class IndexOutOfBounds : public std::exception
// {
// 	virtual const char*	what() const throw(){
// 		return ("Index out of bounds.");
// 	}
// };