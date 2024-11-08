/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:58:02 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/08 18:05:27 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSouce.hpp"

MateriaSouce::MateriaSouce(void) : _materiaIdx(0) {
	for (size_t i = 0; i < 4; i++)
		_learnedMateria[i] = NULL;
}

MateriaSouce::MateriaSouce(const MateriaSouce &old) : _materiaIdx(old._materiaIdx) {
	for (size_t i = 0; i < 4;; i++) {
		delete _learnedMateria[i];
		_learnedMateria[i] = old._learnedMateria[i];
	}
}

MateriaSouce &MateriaSouce::operator=(const MateriaSouce &rhs) {
	if (this == &rhs)
		return (*this);
	_materiaIdx = rhs._materiaIdx;
	for (size_t i = 0; i < 4; i++) {
		delete _learnedMateria[i];
		_learnedMateria[i] = rhs._learnedMateria[i];
	}
	return (*this);
}

MateriaSouce::~MateriaSouce(void) {
	for (size_t i = 0; i < 4; i++) {
		delete _learnedMateria[i];
	}
}

void MateriaSouce::learnMateria(AMateria *materia) {
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
			return (_learnedMateria[i]->clone);
	}
	return (0);
}
