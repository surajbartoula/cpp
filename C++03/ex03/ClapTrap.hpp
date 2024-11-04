/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:22:52 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/04 19:42:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
	std::string _name;
	unsigned int _hit;
	unsigned int _energy;
	unsigned int _damage;
public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap &old);
	ClapTrap &operator=(const ClapTrap &rhs);
	virtual ~ClapTrap(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

//if the destructor is not virtual deleting an object of a derived class (like ScavTrap) through
//a pointer to the base class (like ClapTrap*) will result in undefined behavior.
//eg ClapTrap* ptr = new ScavTrap("Scavvy"); is not possible.
//Using the same name (_name in this case) creates variable shadowing. This means that:

//VARIABLE SHADOWING
//DiamondTrap's _name hides ClapTrap's _name when accessed directly from within DiamondTrap.
//If you want to access ClapTrap’s _name specifically, you need to do so with an explicit 
//reference like ClapTrap::_name.