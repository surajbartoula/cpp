/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:15:36 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/21 23:20:37 by sbartoul         ###   ########.fr       */
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

	typename std::stack<T>::container_type::iterator begin() {
		return (std::stack<T>::c.begin());
	}

	typename std::stack<T>::container_type::iterator end() {
		return (std::stack<T>::c.end());
	}
};

#endif