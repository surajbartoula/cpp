/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:35:16 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/12 18:06:28 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob"); 

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}

//Dynamic dispatch
//How It Works: When you call a virtual function through a base class pointer or reference, C++ uses a
//mechanism called the virtual table (vtable) to look up and call the correct overridden function at runtime.

//Materias must be deleted when a Character is destroyed.


//OWNERSHIP TRANSFER
//When new Ice() and new Cure() are passed to src->learnMateria(), the
//MateriaSource instance takes ownership of these objects. This means
//MateriaSource will be responsible for deleting them when necessary
//(e.g., during destruction or when learning new Materia and replacing existing ones).
//When me and src are deleted at the end of main, their destructors ensure 
//that all AMateria objects they manage are properly deleted to avoid memory leaks.