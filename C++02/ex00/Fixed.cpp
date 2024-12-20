/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:42:30 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/21 11:54:55 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &old) {
	std::cout << "Copy constructor called" << std::endl;
	*this = old; //copy the contents of the old object to the current object(this).
}

Fixed &Fixed::operator=(const Fixed &old) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&old == this) //check for self assignment. it ensure the object doestnot assign itself (a = a).
		return (*this);
	_rawBits = old.getRawBits(); //copy data from old object.
	return (*this); //return current object by reference which allow for chained assignment. (eg. a = b = c).
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

const int Fixed::_fracBits = 8;
