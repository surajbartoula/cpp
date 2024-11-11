/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:17:37 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/11 15:02:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("default") {
	for (size_t i = 0; i < 4; i++) {
		_inventory[i] = NULL;
		_equipped[i] = false;
	}
}

Character::Character(const std::string &name) : _name(name) {
	for (size_t i = 0; i < 4; i++) {
		_inventory[i] = NULL;
		_equipped[i] = false;
	}
}

Character::Character(const Character &old) : _name(old._name) {
	for (size_t i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = old._inventory[i];
		_equipped[i] = old._equipped[i];
	}
}

Character &Character::operator=(const Character &rhs) {
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	for (size_t i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = rhs._inventory[i];
		_equipped[i] = rhs._equipped[i];
	}
	return (*this);
}

Character::~Character(void) {
	for (size_t i = 0; i < 4; i++)
		delete _inventory[i];
}

const std::string &Character::getName() const {
	return (_name);
}

void Character::equip(AMateria *m) {
	for (size_t i = 0; i < 4; i++) {
		if (_equipped[i] == false) { //Check if any slot available
			delete _inventory[i]; //if empty slot found delete the exisiting obj in _inventory[i] to avoid memory leaks.
			_inventory[i] = m; //Replace with with m.
			_equipped[i] = true; //Slot is filled.
			return ;
		}
	}
}

void Character::unequip(int idx) { //remove te equipped slot specified index.
	if (idx >= 0 && idx < 4)
		_equipped[idx] = false;
}

void Character::use(int idx, ICharacter &target) { //Called on Materia at the specified index(idx) and interacts with the target character.
	if (idx >= 0 && idx < 4 && _equipped[idx] == true)
		_inventory[idx]->use(target);
}
