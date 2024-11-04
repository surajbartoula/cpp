/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:23:22 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/04 19:21:04 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamond("Bob");
	diamond.attack("Brian");
	diamond.guardGate();     //ScavTrap's special function.
	diamond.highFivesGuys(); //FragTrap's special function.
	diamond.beRepaired(1);
	diamond.takeDamage(1);
	diamond.whoAmI();		 //Diamond's own special function.

	return (0);
}

//The -Wshadow flag enables warnings about variable shadowing.
//Variable shadowing occurs when a local variable in a certain 
//scope has the same name as a variable in an outer scope (such as a member variable in a class),
//which can lead to bugs or confusing code.

//The -Wno-shadow flag disables shadow warnings. This is useful if you
//have legitimate cases where shadowing is intended or unavoidable, and 
//you want to avoid the warnings. By default, shadowing warnings are not 
//enabled, so you would typically use -Wshadow to enable them or -Wno-shadow 
//to disable them if -Wshadow was enabled globally.
