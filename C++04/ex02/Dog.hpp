/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:29:14 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/13 12:09:36 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *brain;
public:
	Dog(void);
	Dog(const Dog &old);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog(void);

	void makeSound(void) const; //the method doesnot change any member variable of the class or call non-const member func that could modify the object.
	void printidea(void) const;
};

#endif