/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:05:10 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/21 17:27:49 by sbartoul         ###   ########.fr       */
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
