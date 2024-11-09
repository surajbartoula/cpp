/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:58:02 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/09 10:10:26 by sbartoul         ###   ########.fr       */
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
		if (_learnedMateria[i]->getType() == type)
			return (_learnedMateria[i]->clone());
	}
	return (0);
}
