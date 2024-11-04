/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:27:08 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/04 11:15:55 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	std::cout << "Creating a ClapTrap object:" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("Target1");
	clap.takeDamage(25);
	clap.beRepaired(10);

	std::cout << "Creating a ScapTrap object:" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("Target2");
	scav.guardGate();

	return (0);
}
