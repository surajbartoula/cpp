/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:29:06 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/05 23:43:21 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Default Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &old) : Animal(old) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = old.type;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	type = rhs.type;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Bark" << std::endl;
}
