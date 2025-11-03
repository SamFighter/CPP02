#include "Fixed.hpp"

/* ========== Different constructor to handle the fixed and float point =========== */

Fixed::Fixed() : _fixePoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value * (1 << _fracBits));
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixePoint = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	_fixePoint = copy.getRawBits();
}

/* =================  Overload operator   ==================== */

std::ostream& operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(copy.getRawBits());
	return (*this);
}

/* ======================== Destructor ======================== */

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* ======================== Public function =================== */

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixePoint);
}

void Fixed::setRawBits( int const raw ) {
	this->_fixePoint = raw;
}

float	Fixed::toFloat( void ) const {
	float value = (float)_fixePoint / (1 << _fracBits);
	return (value);
}

int		Fixed::toInt( void ) const {
	int value = _fixePoint / (1 << _fracBits);
	return (value);
}
