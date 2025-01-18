/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:12:41 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/18 21:30:09 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *arr, unsigned int len, void (*f)(const T &item)) {
	for (unsigned int i = 0; i < len; i++)
	{
		f(arr[i]); //Applying function to each element of an array
	}
}

#endif