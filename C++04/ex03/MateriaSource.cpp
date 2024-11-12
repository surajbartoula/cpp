/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:58:02 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/12 18:03:11 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _materiaIdx(0) {
	for (size_t i = 0; i < 4; i++)
		_learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &old) : _materiaIdx(old._materiaIdx) {
	for (size_t i = 0; i < 4; i++) {
		delete _learnedMateria[i];
		_learnedMateria[i] = old._learnedMateria[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	if (this == &rhs)
		return (*this);
	_materiaIdx = rhs._materiaIdx;
	for (size_t i = 0; i < 4; i++) {
		delete _learnedMateria[i];
		_learnedMateria[i] = rhs._learnedMateria[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	for (size_t i = 0; i < 4; i++) {
		delete _learnedMateria[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (_materiaIdx < 4) {
		delete _learnedMateria[_materiaIdx];
		_learnedMateria[_materiaIdx] = materia;
		_materiaIdx++;
	}
	else
	{
		_materiaIdx = 0;
		delete _learnedMateria[_materiaIdx];
		_learnedMateria[_materiaIdx] = materia;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (size_t i = 0; i < 4; i++) {
		if (_learnedMateria[i]->getType() == type) //getType() method of Amateria object stored at _learnedMateria[i] matches the type parameter passed to the function.
			return (_learnedMateria[i]->clone()); //return a copy of AMateria
	}
	return (0);
}

//Why MateriaSource
//Reusability: The MateriaSource can create multiple copies of an AMateria without needing to directly construct each one. This is efficient because you don't need to know how to create the AMateria from scratch each time; you just request it by type.
//Modularity: The createMateria method allows code that uses MateriaSource to remain decoupled from the specific details of AMateria types. This makes it easy to add new AMateria types in the future.
//Ease of Use: By identifying AMateria objects by their type string (e.g., "ice", "fire"), the creation process is simplified to calling createMateria("ice"), which returns a new AMateria of that type.

//To create a new "ice" AMateria, you simply call:
//AMateria* newIce = materiaSource->createMateria("ice");
//The MateriaSource does not directly create new types of AMateria from scratch; it relies on previously learned types to generate new instances.