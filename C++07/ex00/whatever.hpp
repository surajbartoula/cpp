/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:57:54 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/18 20:45:31 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T &min(T &a, T &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T &max(T &a, T &b) {
	if (a > b)
		return (a);
	return (b);
}

#endif