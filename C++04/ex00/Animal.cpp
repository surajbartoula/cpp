/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:55:40 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/05 22:34:30 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//Constructor using member initializer list.
Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &old) : type(old.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this == &rhs) {
		return (*this);
	}
	type = rhs.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a sound" << std::endl;
}

const std::string &Animal::getType(void) const {
	return (type);
}
