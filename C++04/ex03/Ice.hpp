/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:13:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 23:05:18 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice &old);
	Ice &operator=(const Ice &rhs);
	~Ice(void);

	AMateria *clone(void) const;
	void use(ICharacter &target);
};

#endif