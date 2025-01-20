/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:38:44 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/20 10:50:50 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T> Array<T>::Array(void): _size(0), _arr(NULL) {}

template <typename T> Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]) {}

template <typename T> Array<T>::Array(const Array<T> &old): _size(old.size()) {
	_arr = new T[old.size()];
	for (unsigned int i = 0; i < old.size(); i++)
		_arr[i] = old[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &rhs) {
	if (this == &rhs)
		return (*this);
	delete[] _arr; //Before allocating new memory, the exisiting array if any is deleted
	_arr = new T[rhs.size()];
	_size = rhs.size();
	for (unsigned int i = 0; i < rhs.size(); i++)
		_arr[i] = rhs[i];
	return (*this);
}

template <typename T> Array<T>::~Array(void) {delete[] _arr;}

template <typename T> T &Array<T>::operator[](const unsigned int idx) {
	//idx < 0 comparision is removed cause unsigned int cannot have negative value. If given negative value
	//eg idx = -1, implicit type conversion takes place where it is converted to large value 4294967295
	//plus in linux give error if we say if idx < 0
	if (idx >= _size)
		throw std::out_of_range("Index out of range");
	return (_arr[idx]);
}

template <typename T> const T &Array<T>::operator[](const unsigned int idx) const {
	if (idx >= _size)
		throw std::out_of_range("Index out of range");
	return (_arr[idx]);
}

template <typename T> unsigned int Array<T>::size() const {return (_size);}

#endif