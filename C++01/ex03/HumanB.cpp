/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:55:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/15 20:45:50 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) const {
	if (_weapon != NULL)
		std::cout << _name << " attacked with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << "cannot attack without a weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}