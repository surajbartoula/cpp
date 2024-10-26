/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:41:27 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/25 20:23:09 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	// std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &old) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = old;
}

Fixed::Fixed(const int num) {
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (num << _fracBits);
}

Fixed::Fixed(const float num) {
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(num * (1 << _fracBits));
}

Fixed &Fixed::operator=(const Fixed &old) {
	if (this != &old) //check for self assignment. it ensure the object doestnot assign itself (a = a).
		this->_rawBits = old.getRawBits();
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this); //return current object by reference which allow for chained assignment. (eg. a = b = c).
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(const int raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

int Fixed::toInt(void) const {
	return (int)(this->_rawBits >> _fracBits);
}

float Fixed::toFloat(void) const {
	return (float)(this->_rawBits) /(float)(1 << _fracBits);
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
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
	Fixed old(*this); //Point to the old value
	++(*this); //Use pre-increment to increase the value.
	return (old);
}

//Pre increment
Fixed &Fixed::operator++(void) {
	_rawBits++;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	--(*this);
	return (old);
}

Fixed &Fixed::operator--(void) {
	_rawBits++;
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
