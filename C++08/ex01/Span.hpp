/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:07:52 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/21 22:31:17 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {
private:
	std::vector<unsigned int> _nums;
	unsigned int _maxNums;
	bool _isSorted;
public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &old);
	Span &operator=(const Span &rhs);

	void addNumber(unsigned int num);
	template<typename InputIt>
	void addNumber(InputIt first, InputIt last);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	~Span(void);
};

template<typename InputIt>
void Span::addNumber(InputIt first, InputIt last) {
	if (std::distance(first, last) + _nums.size() > _maxNums)
		throw std::length_error("Span is full");
	for (InputIt it = first; it != last; it++)
		_nums.push_back(*it);
	if (_nums.size() > 1)
		_isSorted = false;
}

#endif

//How Compilation Works
// The Compiler reads the header files first.
//For template, the compiler instantiates the template when it encounters it but to instantiate it
//needs the full definition 