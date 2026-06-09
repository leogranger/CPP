#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <cmath>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const Fixed& other);        // constructeur de copie
		Fixed(int fixed);
		Fixed(float fixed);
		~Fixed(void);
		Fixed&	operator=(const Fixed& other);
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt( void ) const;
		float	toFloat( void ) const;
		static Fixed&	min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a,const Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a,const Fixed &b);

	private :
		int			_fixed;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif