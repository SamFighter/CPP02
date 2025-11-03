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

		bool	operator==(const Fixed &copy) const;
		bool	operator<=(const Fixed &copy) const;
		bool	operator>=(const Fixed &copy) const;
		bool	operator!=(const Fixed &copy) const;
		bool	operator<(const Fixed &copy) const;
		bool	operator>(const Fixed &copy) const;

		Fixed &operator--();
		Fixed &operator++();
		Fixed operator--(int);
		Fixed operator++(int);

		Fixed operator-(const Fixed &copy);
		Fixed operator+(const Fixed &copy);
		Fixed operator*(const Fixed &copy);
		Fixed operator/(const Fixed &copy);
		~Fixed();

		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		float			toFloat( void ) const;
		int				toInt( void ) const;
		static Fixed		&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(Fixed const &f1, Fixed const &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(Fixed const &f1, Fixed const &f2);
};

std::ostream& operator<<(std::ostream &os, const Fixed &obj);

#endif
