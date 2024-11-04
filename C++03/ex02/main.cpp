/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:27:08 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/01 22:18:53 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap frag1("TrapStudent");
	FragTrap frag2("TrapMaster");
	frag2.attack("TrapStudent");
	frag2.attack("TrapStudent");
	frag2.attack("TrapStudent");
	frag1.attack("TrapMaster");

	frag1.highFivesGuys();
	frag2.highFivesGuys();

	return (0);
}