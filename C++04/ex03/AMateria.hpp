/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:25:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/08 19:12:04 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
class ICharacter; //Forward declaration to avoid circular dependencies.

class AMateria {
protected:
	std::string materialType;
public:
	AMateria(void);
	AMateria(const std::string &name);
	AMateria(const AMateria &old);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria(void);

	std::string const &getType() const;
	//Pure virtual function to be implemented by derived class.
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif