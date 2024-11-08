/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:55:54 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 13:27:43 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;
public:
	Animal(void);
	Animal(const Animal &old);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	const std::string &getType(void) const;
};

#endif