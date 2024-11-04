/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:17:08 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/04 13:49:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hit= 100;
	this->_damage = 20;
	this->_energy = 50;
}

ScavTrap::ScavTrap(const ScavTrap &old) : ClapTrap(old) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->_hit = old._hit;
	this->_damage = old._damage;
	this->_energy = old._energy;
	this->_name = old._name;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_hit = 100;
	this->_damage = 20;
	this->_energy = 50;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "ScavTrap copy assignment constructor called" << std::endl;
	if (this != &rhs) {
		this->_damage = rhs._damage;
		this->_energy = rhs._energy;
		this->_hit = rhs._hit;
		this->_name = rhs._name;
	}
	return (*this);
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in gateKeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (_hit > 0 && _energy > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
		_energy--;
	} else {
		std::cout << "ScavTrap " << _name << " has no energy or hit points to attack!" << std::endl;
	}
}

//Since construction in inheritance happens from the base class up to the derived class, and destruction 
//happens in reverse order, the program will first construct the ClapTrap part of ScavTrap before constructing
//the ScavTrap-specific attributes. During destruction, it will reverse this order.

//Why destructor in reverse order?
//When an object of a derived class (like ScavTrap) is destroyed, it may rely on resources or functionality inherited 
//from its base class (like ClapTrap). If the base class were destroyed first, the derived class would lose access to 
//these resources, potentially causing undefined behavior if the derived class still needs to perform any cleanup specific to itself.

//In C++, proper construction and destruction chaining refers to how constructors and destructors of base and derived classes
//are called during the creation and destruction of objects. When you create an object of a derived class, the constructor of the base
//class is called first, and when the object is destroyed, the destructor of the derived class is called first, followed by the destructor
//of the base class. This ensures that the object is fully initialized before it's used and cleaned up properly when it goes out of scope.