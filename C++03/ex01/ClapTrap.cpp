/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:19:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/28 21:10:09 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hit(10), _energy(10), _damage(0) {
	std::cout << "ClaTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old) : _name(old._name), _hit(old._hit), _energy(old._energy), _damage(old._damage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	std::cout << "ClapTrap copy assignment constructor called"  << std::endl;
	if (this == &rhs)
		return (*this);
	_damage = rhs._damage;
	_energy = rhs._energy;
	_hit = rhs._hit;
	_name = rhs._name;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_energy > 0 && _hit > 0) {
		_energy--;
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " has no energy or hit points to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit > 0) {
		_hit -= amount;
		if (_hit < 0)
			_hit = 0;
		std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage! Hit points left: " << _hit << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " is already out of hit points!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy > 0 && _hit > 0) {
		_hit += amount;
		_energy--;
		std::cout << "ClapTrap " << _name << " has repaired itself for " << amount << " hit points! Hit points now: " << _hit << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " has no energy or hit points to repair!" << std::endl;
	}
}
