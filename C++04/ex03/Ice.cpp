/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:13:55 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 21:08:46 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &old) : AMateria(old) {}

Ice &Ice::operator=(const Ice &rhs) {
	(void)rhs;
	return (*this);
}

Ice::~Ice(void) {}

AMateria *Ice::clone() const {
	Ice *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}