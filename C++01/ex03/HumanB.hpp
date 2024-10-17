/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:56:00 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/15 20:41:07 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		const std::string _name;
		Weapon		*_weapon;
	public:
		HumanB(const std::string &name);
		~HumanB(void);
		void attack(void) const;
		void setWeapon(Weapon &weapon);
};

#endif