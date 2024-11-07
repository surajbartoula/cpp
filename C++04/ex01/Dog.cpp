/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:29:06 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 11:37:01 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : brain(new Brain) {
	std::cout << "Default Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &old) : Animal(old), brain(new Brain(*old.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = old.type;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const {
	std::cout << "Woof!" << std::endl;
}

void Dog::printidea(void) const {
	brain->printidea();
}
