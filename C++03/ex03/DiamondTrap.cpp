/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:35 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/04 20:19:29 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("default") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::_name = _name + "clap_name"; //changing the claptrap name to diamondtrap name.
	ClapTrap::_hit = FragTrap::_hit; //diamondtrap inherits from hit from claptrap and we are overriding with fragtrap.
	ClapTrap::_energy = ScavTrap::_energy;
	ClapTrap::_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	std::cout << "DiamondTrap name constructor called" << std::endl;
	ClapTrap::_hit = FragTrap::_hit;
	ClapTrap::_energy = ScavTrap::_energy;
	ClapTrap::_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &old) : ClapTrap(old), ScavTrap(old), FragTrap(old), _name(old._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = old._name; //Sets DiamondTrap's own attribute.
	ClapTrap::_name = old.ClapTrap::_name; //Sets Claptrap's name within DiamondTrap.
	_hit = old._hit;
	_energy = old._energy;
	_damage = old._damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &rhs) { //self assignment check a = a
		_name = rhs._name;
		ClapTrap::_name = rhs.ClapTrap::_name;
		_hit = rhs._hit;
		_energy = rhs._energy;
		_damage = rhs._damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << _name << ", ClapTrap name is " << ClapTrap::_name << std::endl;
}

//These attributes (ClapTrap::_name, _hit, _energy, _damage) belong to base classes (ClapTrap, ScavTrap, and FragTrap)
//from which DiamondTrap inherits. You can’t directly initialize them in DiamondTrap's initializer list because 
//they are part of the base class structure, not directly declared in DiamondTrap.