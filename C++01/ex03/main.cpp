/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:11:18 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/18 10:38:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		Weapon  club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

//Differences between pointer and reference.
//* can be initialized to nullptr and assigned another address later.
//& cannot change initialization
//* needs explicit dereferencing but & is automatically dereferenced.
//* stores the address of object but & act as an alias to an existing object.
//* can be itterated with array but not applicable for direct iteration over arrays.

//If there is a chance that the weapon might not exist or might need to be set to nullptr use pointer.
//A character might not have weapon and u want to dynamically allocate or deallocate the weapon use pointer.
//If u have derived classes of Weapon (like Sword, Bow etc) and need to store them in a way that respect polymerphism use pointer.
//Reassigning to different objects then use pointer.

//A character must have a weapon at all time then use reference.
