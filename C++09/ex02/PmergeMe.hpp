/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:26:25 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/01 00:55:20 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cerrno>
#include <climits>

class PmergeMe {
private:
	template <typename T>
	void insert_with_jacobsthal(std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend);

	template<typename T>
	void swap_adjacent_pairs(T& container, int order, typename T::iterator end);

	template <typename T>
	void merge_insertion_sort(T& container, int order);

	template<typename T>
	void swap_pair(T it, int order);
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe& old);
	PmergeMe& operator=(const PmergeMe& rhs);
	~PmergeMe();

	void sort_vec(std::vector<int>& vec);
	void sort_deque(std::deque<int>& deque);
};

long jacobsthal_numbers(long n);

#endif