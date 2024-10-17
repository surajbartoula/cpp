/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:53:48 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/15 20:36:11 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	private:
		std::string _type;
	public:
		Weapon(const std::string &type);
		~Weapon(void);
		const std::string &getType(void) const; //Method will not modify the member variables and return by reference so threre is no dublication of obj
		void setType(const std::string &type);
};

#endif