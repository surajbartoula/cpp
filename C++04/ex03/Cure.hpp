/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:12:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/09 09:56:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure &old);
	Cure &operator=(const Cure &rhs);
	~Cure(void);

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif
