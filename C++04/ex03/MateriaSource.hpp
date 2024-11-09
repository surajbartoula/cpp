/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:58:12 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/08 21:03:32 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *_learnedMateria[4];
	unsigned int _materiaIdx;
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &old);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource(void);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(const std::string &type);
};

#endif