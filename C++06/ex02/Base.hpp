/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:40:05 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/16 20:39:23 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
	virtual ~Base(void) {};
};

#endif

//If the base class serves as an interface or a polymorphic base class and does not require any other
//functionality, a public virtual destructor is sufficient. It ensures that:
//The class can act as a polymorphic base class.
//The derived class destructors are properly called.