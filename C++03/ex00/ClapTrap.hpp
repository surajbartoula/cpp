/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:19:17 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/28 17:46:37 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hit;
	unsigned int _energy;
	unsigned int _damage;
public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap &old);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif