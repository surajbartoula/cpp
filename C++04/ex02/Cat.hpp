/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:30:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 11:38:33 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef CAT_HPP
 #define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat: public Animal {
private:
	Brain *brain;
public:
	Cat(void);
	Cat(const Cat &old);
	Cat& operator=(const Cat &rhs);
	virtual ~Cat(void);

	void makeSound(void) const;
	void printidea(void) const;
};

 #endif