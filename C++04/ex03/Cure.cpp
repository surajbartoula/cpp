/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:12:45 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 21:43:09 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &old) : AMateria(old) {}

Cure &Cure::operator=(const Cure &rhs) {
	(void)rhs;
	return (*this);
}

Cure::~Cure(void) {}

AMateria *Cure::clone() const {
	Cure *clone = new Clone();
	return (clone);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heels " << target.getName() << "s wounds *" << std::endl;
}