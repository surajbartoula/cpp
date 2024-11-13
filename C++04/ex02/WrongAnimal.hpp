/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:29:00 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/13 10:10:14 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& old);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal(void);

	void makeSound(void) const;
	const std::string &getType(void) const;
};

#endif