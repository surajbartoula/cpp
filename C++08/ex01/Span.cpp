/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:34:39 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/22 20:18:00 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Default-initialization for a std::vector constructs an empty vector with no elements.
Span::Span(void): _nums(), _maxNums(10), _isSorted(true) {}
Span::Span(unsigned int n): _nums(), _maxNums(n), _isSorted(true) {}
Span::Span(const Span &old)
: _nums(old._nums), _maxNums(old._maxNums), _isSorted(old._isSorted) {}

Span &Span::operator=(const Span &rhs) {
	if (this == &rhs)
		return (*this);
	_nums = rhs._nums;
	_maxNums = rhs._maxNums;
	_isSorted = rhs._isSorted;
	return (*this);
}

Span::~Span(void) {}

void Span::addNumber(unsigned int num) {
	if (_nums.size() < _maxNums)
	{
		_nums.push_back(num);
		if (_nums.size() > 1)
			_isSorted = false;
	}
	else
		throw std::length_error("Span is full");
}

unsigned int Span::shortestSpan(void) {
	if (_nums.size() < 2)
		throw std::length_error("Span has less than 2 elements");
	if (_isSorted == false)
	{
		std::sort(_nums.begin(), _nums.end());
		_isSorted = true;
	}
	std::vector<unsigned int> diffs;
	for (std::vector<unsigned int>::iterator it = _nums.begin(); it != _nums.end() - 1; it++)
		diffs.push_back(*(it + 1) - *it);
	return (*std::min_element(diffs.begin(), diffs.end()));
}

unsigned int Span::longestSpan(void) {
	if (_nums.size() < 2)
		throw std::length_error("Span has less than 2 elements");
	if (_isSorted == false)
	{
		std::sort(_nums.begin(), _nums.end());
		_isSorted = true;
	}
	return (*(_nums.end() - 1) - *_nums.begin());
}
//The std::min_element function is part of the C++ Standard Library and is used to find the smallest element
//in a range. It returns an iterator pointing to the smallest element.
//Return value of std::min_element if the range is empty, it returns last.
