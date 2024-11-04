/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:23:03 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/01 22:23:05 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hit = 100;
	this->_damage = 30;
	this->_energy = 100;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_hit = 100;
	this->_damage = 30;
	this->_energy = 100;
}

FragTrap::FragTrap(const FragTrap &old) : ClapTrap(old) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->_hit = old._hit;
	this->_damage = old._damage;
	this->_energy = old._energy;
	this->_name = old._name;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_damage = rhs._damage;
		this->_energy = rhs._energy;
		this->_hit = rhs._hit;
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " requests high fives!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (_hit > 0 && _energy > 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
		_energy--;
	} else {
		std::cout << "FragTrap " << this->_name << " has no energy or hit points to attack!" << std::endl;
	}
}