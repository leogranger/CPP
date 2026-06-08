#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <math.h>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const Fixed& other);        // constructeur de copie
		Fixed(int fixed);
		Fixed(float fixed);
		~Fixed(void);
		Fixed&	operator=(const Fixed& other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt( void ) const;
		float	toFloat( void ) const;

	private :
		int			_fixed;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif