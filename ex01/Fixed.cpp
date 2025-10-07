#include "Fixed.hpp"

Fixed::Fixed() : _fixePoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	_fixePoint = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copy.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixePoint);
}

void Fixed::setRawBits( int const raw ) {
	this->_fixePoint = raw;
}
