/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:48:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/17 23:42:10 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int	size;

	size = 20;
	Zombie	*horde = zombieHorde(size, "Zom");
	for (int i = 0; i < size; i++) {
		horde[i].announce();
	}
	delete[] horde;
}

//Default constructor is called first. then with setter the name is filled.