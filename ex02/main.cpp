#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "===== My own test =====\n" << std::endl;
	Fixed c(Fixed(1.05f));
	Fixed d(Fixed(12.05f));
	Fixed const e(Fixed(9.04f) / Fixed(3));
	std::cout << "c = " << c << " and a = "<< a << "\nmin : " << Fixed::min( c, a ) << std::endl;
	std::cout << "c = " << c << " and a = "<< a << "\nmax : " << Fixed::max( c, a ) << "\n" << std::endl;
	std::cout << "const b = " << b << " and const e = " << e << "\nconst min : " << Fixed::min( b, e ) << std::endl;
	std::cout << "const b = " << b << " and const e = " << e << "\nconst max : " << Fixed::max( b, e ) << "\n" << std::endl;
	std::cout << "12 / 4 = " << (Fixed(12) / Fixed(4)) << std::endl;
	std::cout << "5 * 9 = " << (Fixed(5) * Fixed(9)) << std::endl;
	std::cout << "4 - 4 = " << (Fixed(4) - Fixed(4)) << std::endl;
	std::cout << "12.05 + 0.05 = " << (Fixed(12.05f) + Fixed(0.05f)) << std::endl;
	std::cout << "12 / 0 = " << (Fixed(12) / Fixed(0)) << std::endl;
	return 0;
}
