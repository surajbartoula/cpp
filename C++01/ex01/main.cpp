/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:48:41 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/29 19:16:49 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int main(void) {
	int	size;

	size = 20;
	Zombie	*horde = zombieHorde(size, "Zom");
	for (int i = 0; i < size; i++) {
		horde[i].announce();
	}
	delete [] horde;
}
