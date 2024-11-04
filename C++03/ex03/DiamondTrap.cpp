/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:35 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/02 20:36:51 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("default") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::_name = _name + "clap_name";
	ClapTrap::_hit = FragTrap::_hit;
	ClapTrap::_energy = ScavTrap::_energy;
	ClapTrap::_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &old) : ClapTrap(old), ScavTrap(old), FragTrap(old), _name(old._name) {
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	std::cout << "DiamondTrap assignment operator called for " << _name << std::endl;
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_name = rhs._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << _name << ", ClapTrap name is " << ClapTrap::_name << std::endl;
}
