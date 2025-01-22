/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:15:36 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/22 12:37:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	//std::stack<T>::c: The underlying container of the stack (std::vector or std::deque).
	typename std::stack<T>::container_type::iterator begin() {
		return (std::stack<T>::c.begin());
	}

	typename std::stack<T>::container_type::iterator end() {
		return (std::stack<T>::c.end());
	}
};

#endif

//The std::stack<T> class does not provide direct access to its elements (only to top(),
//pop(), and push()), but by exposing the underlying container (c), MutantStack can access
//and iterate through the container's elements.

//Difference between deque and vector is: vector is store in contiguous block of memory but
//deque is implemented as a sequence of smaller fixed-size blocks of memory. Accesing element
//this allows the deque to insert and remove elements at both ends without reallocation of the 
//entire data structure.
//[ Block 1 (5 elements) | Block 2 (4 elements) | Block 3 (3 elements) | Block 4 (2 elements) ] -> [ Pointer array storing pointers to these blocks ]
