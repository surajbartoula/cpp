/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:29:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/05 23:32:47 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog &old);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog(void);

	void makeSound(void) const;
};

#endif