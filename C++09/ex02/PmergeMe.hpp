/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:26:25 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/04 17:21:30 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cerrno>
#include <climits>

class PmergeMe {
private:
	std::vector<int> vec;
	std::list<int> lst;
	template <typename T>
	void insert_with_jacobsthal(std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend);

	template<typename T>
	void swap_adjacent_pairs(T& container, int order, typename T::iterator end);

	template <typename T>
	T& merge_insertion_sort(T& container, int order);

	template<typename T>
	void swap_pair(T it, int order);
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe& old);
	PmergeMe& operator=(const PmergeMe& rhs);
	~PmergeMe();

	void fill(int argc, char **argv);
	void sort();
	void print_argv(const std::vector<int>& vec);
};

long jacobsthal_numbers(long n);

template <typename Iterator>
bool issorted(Iterator begin, Iterator end);

#endif