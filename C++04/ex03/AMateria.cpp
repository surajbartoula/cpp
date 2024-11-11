/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:25:42 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/11 12:06:19 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) {
	materiaType = "default";
}

AMateria::AMateria(const std::string &type) {
	materiaType = type;
}

AMateria::AMateria(const AMateria &old) {
	materiaType = old.materiaType;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	(void)rhs;
	return (*this);
}

AMateria::~AMateria(void) {}

const std::string &AMateria::getType() const
{
	return (materiaType);
}

void AMateria::use(ICharacter &target) {
	(void)target;
}
