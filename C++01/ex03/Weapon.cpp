/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:58:49 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/15 20:43:57 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type): _type(type) {} //first weapon class scope resolution operator second constructor

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const {
	return (_type);
}

void	Weapon::setType(const std::string &type) {
	this->_type = type;
}
