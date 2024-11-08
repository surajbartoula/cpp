/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:12:58 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/07 23:05:35 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure &old);
	Cure &operator=(const Cure &rhs);
	~Cure(void);
};

#endif