/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:45:01 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/23 22:38:24 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
	std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y) {
	std::cout << "Point float constructor called" << std::endl;
}

Point::Point(const Point &old) : x(old.x), y(old.y) {
	std::cout << "Point copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &old) {
	(void)old;
	std::cout << "Point copy assignment constructor called" << std::endl;
	return (*this);
}

bool Point::operator==(const Point &rhs) const {
	return (x == rhs.x && y == rhs.y);
}

Point::~Point(void) {
	std::cout << "Point destructor called" << std::endl;
}

const Fixed &Point::getX(void) const {return (x);}
const Fixed &Point::getY(void) const {return (y);}