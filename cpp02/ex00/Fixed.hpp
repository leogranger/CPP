#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const Fixed& other);        // constructeur de copie
    		Fixed(int fixed);
		~Fixed(void);
		Fixed& operator=(const Fixed& other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	private :
		int			_fixed;
		static const int	_bits = 8;
};

#endif