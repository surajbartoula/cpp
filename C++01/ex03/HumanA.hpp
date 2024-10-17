/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:02:25 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/15 18:50:26 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string _name;
	Weapon		&_weapon; //holds ref to weapon object(always armed)
public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA(void);
	void attack(void) const;
};

#endif
