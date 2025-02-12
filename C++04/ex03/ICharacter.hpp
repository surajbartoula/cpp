/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:08:15 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/12 23:15:59 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter(void) {}
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	//equip function should find the first empty slot (from 0 to 3) and add the AMateria object.
	//If the inventory is full, it should do nothing.
	virtual void unequip(int idx) = 0;
	//unequip function should remove the AMateria from the specified slot but not delete it
	//(set the slot to nullptr).
	virtual void use(int idx, ICharacter &target) = 0;
	//use function should call the use() method of the AMateria in the specified slot if it exists.
};

#endif

//you do not need to create a .cpp file for IMateriaSource.hpp. This is an interface class, 
//which means it only declares pure virtual functions without providing any implementation.

//When to Create a .cpp File:
//If your class had methods with actual implementations (even default methods), you would put those in a .cpp file.
//For interface classes (pure abstract classes) like IMateriaSource, where you only need to declare the interface, a header file alone is sufficient.
