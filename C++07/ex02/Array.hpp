/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:09:39 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/17 20:38:30 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <class T> class Array {
private:
	unsigned int _size;
	T *_arr;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array& old);
	Array &operator=(const Array& rhs);
	~Array(void);

	T &operator[](const unsigned int idx);
	const T &operator[](const unsigned int idx) const;
	unsigned int size() const;
};
#include "Array.tpp"
#endif