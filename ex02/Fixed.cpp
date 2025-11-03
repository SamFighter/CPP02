#include "Fixed.hpp"

/* ========== Different constructor to handle the fixed and float point =========== */

Fixed::Fixed() : _fixePoint(0) {
}

Fixed::Fixed(const int value) {
	this->setRawBits(value * (1 << _fracBits));
}

Fixed::Fixed(const float value) {
	this->_fixePoint = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &copy) {
	_fixePoint = copy.getRawBits();
}

/* =================   Overload operator   ==================== */

std::ostream& operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &copy) {
	this->setRawBits(copy.getRawBits());
	return (*this);
}

bool	Fixed::operator==(const Fixed &copy) const {
	if (this->getRawBits() == copy.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &copy) const {
	if (this->getRawBits() <= copy.getRawBits())
	    return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &copy) const {
	if (this->getRawBits() >= copy.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &copy) const {
	if (this->getRawBits() == copy.getRawBits())
		return (false);
	else
		return (true);
}

bool	Fixed::operator<(const Fixed &copy) const {
	if (this->getRawBits() < copy.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(const Fixed &copy) const {
	if (this->getRawBits() > copy.getRawBits())
		return (true);
	else
		return (false);
}

Fixed& Fixed::operator--() {
	int raw = this->getRawBits();
	this->setRawBits(raw - 1);
	return (*this);
}

Fixed& Fixed::operator++() {
	int raw = this->getRawBits();
	this->setRawBits(raw + 1);
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed copy = *this;
	this->setRawBits(copy.getRawBits() - 1);
	return (copy);
}

Fixed Fixed::operator++(int) {
	Fixed copy = *this;
	this->setRawBits(copy.getRawBits() + 1);
	return (copy);
}

Fixed Fixed::operator-(const Fixed &copy) {
	Fixed result;
	result.setRawBits(this->getRawBits() - copy.getRawBits());
	return (result);
}

Fixed Fixed::operator+(const Fixed &copy) {
	Fixed result;
	result.setRawBits(this->getRawBits() + copy.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &copy) {
	Fixed result;
	result.setRawBits((this->getRawBits() * copy.getRawBits()) >> _fracBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &copy) {
	Fixed result;
	if (copy.getRawBits() != 0) {
		float val1 = this->toFloat();
		float val2 = copy.toFloat();
		int raw = roundf(val1 / val2 * (1 << _fracBits));
		result.setRawBits(raw);
	}
	return (result);
}

/* ======================== Destructor ======================== */

Fixed::~Fixed() {
}

/* ======================== Public function =================== */

int Fixed::getRawBits( void ) const {
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

Fixed&	Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	else if (f2 < f1)
		return (f2);
	else
		return (f1);
}

const Fixed&	Fixed::min(Fixed const &f1, Fixed const &f2) {
	if (f1 < f2)
		return (f1);
	else if (f2 < f1)
		return (f2);
	else
		return (f1);
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	else if (f2 > f1)
		return (f2);
	else
		return (f1);
}

const Fixed&		Fixed::max(Fixed const &f1, Fixed const &f2) {
	if (f1 > f2)
		return (f1);
	else if (f2 > f1)
		return (f2);
	else
		return (f1);
}

