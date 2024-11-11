/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:13:44 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/11 13:39:58 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstddef>

class Character : public ICharacter {
private:
	AMateria *_inventory[4];
	bool _equipped[4];
	std::string _name;
public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &old);
	Character &operator=(const Character &rhs);
	~Character(void);

	const std::string &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif

//When you refer to a concrete class Character, it means a class named Character that is 
//fully defined and can be used to create objects. This class would implement all of its functions,
//including any that it inherits from abstract base classes, if applicable.