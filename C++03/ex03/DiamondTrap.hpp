/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:32 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/04 19:14:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;
public:
	DiamondTrap(void);
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &old);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();
};

#endif
//ScavTrap and FragTrap both inherit from ClapTrap. By default, without any special handling, 
//this would mean that DiamondTrap has two instances of ClapTrap (one from each path).
//To avoid this redundancy, virtual inheritance is used in ScavTrap and FragTrap 
//(virtual public ClapTrap). This tells the compiler to create a single shared instance of ClapTrap in
//DiamondTrap, resolving the diamond problem.