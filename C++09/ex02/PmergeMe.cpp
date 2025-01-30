/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:26:29 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/30 21:34:50 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {};
PmergeMe::PmergeMe(const PmergeMe& old) {(void)old;}
PmergeMe& PmergeMe::operator=(const PmergeMe &rhs) {(void)rhs; return (*this);}
PmergeMe::~PmergeMe() {};

//Jacobsthal numbers are J(0)=0, J(1)=1, J(2)=1, J(3)=3, J(4)=5, J(5)=11, J(6)=21,..
long jacobsthal_numbers(long n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal_numbers(n - 1) + 2 * jacobsthal_numbers(n - 2);
}

void PmergeMe::sort_vec(std::vector<int>& vec) {_merge_insertion_sort<std::vector<int> >(vec, 1);}

void PmergeMe::sort_deque(std::deque<int>& deque) {_merge_insertion_sort<std::deque<int> >(deque, 1);}
