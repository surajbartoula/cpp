/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:12:18 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/04 11:59:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
	std::string _name;
	unsigned int _hit; //ClapTrap health.
	unsigned int _energy; //Required to perfom to attack and repair. Each attack cost 1 energy point. Each repair cost 1 energy point.
	unsigned int _damage; //Every damage amount reduces equal amount of hit point.
public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap &old);
	ClapTrap &operator=(const ClapTrap &rhs);
	virtual ~ClapTrap(void);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif