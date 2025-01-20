/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:12:41 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/20 10:29:36 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(const T &item)) {
	for (std::size_t i = 0; i < len; i++)
	{
		f(arr[i]); //Applying function to each element of an array
	}
}

#endif