/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:44:28 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/23 17:46:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
	_neg = false;
}

Fixed::Fixed(const Fixed &old) {
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = old._rawBits;
	this->_neg = old._neg;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	if (num < 0) {
		_neg = true;
		_rawBits = - num;
		_rawBits <<= _fracBits;
	}
	else
	{
		_neg = false;
		_rawBits = num;
		_rawBits <<= _fracBits;
	}
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	int intPart;
	float fracPart;
	if (num < 0) {
		_neg = true;
		intPart = static_cast<int>(-num);
		fracPart = (- num - intPart);
	}
	else
	{
		_neg = false;
		intPart = static_cast<int>(num);
		fracPart = (num - intPart);
	}
	_rawBits = intPart;
	_rawBits <<= _fracBits;
	float divisor;
	for (int i = 1; i < _fracBits + 1; i++) {
		divisor = 1.0f / pow(2, i);
		if (divisor < fracPart) {
			_rawBits |= pow(2, _fracBits - i);
			fracPart -= divisor;
		}
	}
	const float epsilon = 1.0f / pow(2, _fracBits);
	const float current = abs(toFloat());
	const float target = abs(num);
	if (abs((current + epsilon) - target) < abs(current - target)) //Check if rounding is needed.
		_rawBits++;
}

Fixed &Fixed::operator=(const Fixed &old) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&old == this) //check for self assignment. it ensure the object doestnot assign itself (a = a).
		return (*this);
	_rawBits = old.getRawBits();
	_neg = old._neg;
	return (*this); //return current object by reference which allow for chained assignment. (eg. a = b = c).
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	const float addition = this->toFloat() + rhs.toFloat();
	Fixed res(addition);
	if (addition < 0)
		res._neg = true;
	else
		res._neg = false;
	return (res);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	const float substraction = this->toFloat() - rhs.toFloat();
	Fixed res(substraction);
	if (substraction < 0)
		res._neg = true;
	else
		res._neg = false;
	return (true);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	const float multiplication = this->toFloat() * rhs.toFloat();
	Fixed res(multiplication);
	if (multiplication < 0)
		res._neg = true;
	else
		res._neg = false;
	return (res);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs.toFloat() != 0)
	{
		const float division = this->toFloat() / rhs.toFloat();
		Fixed res(division);
		if (division < 0)
			res._neg = true;
		else
			res._neg = false;
		return (res);
	}
	else
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed(0));
	}
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

int Fixed::toInt(void) const {return (toFloat());}

float Fixed::toFloat(void) const {
	float intPart = _rawBits >> _fracBits;
	int fracPart = _rawBits & (pow(2, _fracBits) - 1);
	if (fracPart == 0) {
		if (_neg == true) {
			return (- intPart);
		}
		return (intPart);
	}
	float decimal = 0.0f;
	for (int i = 1; i < _fracBits + 1; i++) {
		if (((fracPart >> (_fracBits - i)) & 1) == 1)
			decimal += 1.0f / pow(2, i);
	}
	if (_neg == true)
		return (intPart + decimal) * -1;
	return (intPart + decimal);
}

unsigned int Fixed::pow(unsigned int num, unsigned int pow) {
	unsigned int res = 1;
	for (unsigned int i = 0; i < pow; i++)
		res *= num;
	return (res);
}

float Fixed::abs(float num) {
	if (num < 0.0f)
		return (- num);
	return (num);
}

bool Fixed::operator<(const Fixed &rhs) const {
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>(const Fixed &rhs) const {
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(const Fixed &rhs) const {
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return (this->toFloat() != rhs.toFloat());
}

//post increment
Fixed Fixed::operator++(int) {
	const Fixed old(*this);
	operator++();
	return (old);
}

//Pre increment
Fixed &Fixed::operator++(void) {
	Fixed increment;
	increment._rawBits = 1;
	*this = operator+(increment);
	return (*this);
}

Fixed Fixed::operator--(int) {
	const Fixed old(*this);
	operator--();
	return (old);
}

Fixed &Fixed::operator--(void) {
	Fixed decrement;
	decrement._rawBits = 1;
	*this = operator-(decrement);
	return (*this);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

const int Fixed::_fracBits = 8;
