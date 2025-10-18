#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_fixePoint;
		static const int	_fracBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float fvalue);
		Fixed &operator=(const Fixed &copy);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};


#endif
