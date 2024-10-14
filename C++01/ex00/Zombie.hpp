/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:16:35 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/28 22:03:09 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

private: 
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
};

//Function prototypes
Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif