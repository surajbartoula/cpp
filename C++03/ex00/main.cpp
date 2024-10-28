/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:48:17 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/28 20:56:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clap1("Crab");
	ClapTrap clap2("Lobster");

	clap1.attack("Lobster");
	clap1.attack("Lobster");

	clap2.takeDamage(7);
	clap2.beRepaired(5);

	for (int i = 0; i < 9; i++) {
		clap1.attack("Lobster");
	}
	clap1.attack("Lobster");

	return (0);
}
