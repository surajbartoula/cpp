/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:05:10 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/22 10:00:57 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int toFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end()) {
		throw std::invalid_argument("Argument not found");
	}
	return it;
}

#endif

//typename T::iterator can work with any container type such as std::vector, std::list
// Return type is iterator for the container type T
// The typename keyword is required because T::iterator depends on the template parameter T and must
//be explicitly marked as a type.
//std::vector<int>iterator
//In C++, the typename keyword is required in certain contexts to explicitly indicate that a 
//dependent name (e.g., T::iterator) is a type. This ensures that the compiler can correctly parse and understand the code.
//During the first stage of template parsing (before T is known), the compiler treats dependent names as non-types by default.
//To override this behavior and explicitly tell the compiler that T::iterator is a type, you need to use the typename keyword.
