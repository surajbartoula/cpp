/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:26:25 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/01 00:50:23 by sbartoul         ###   ########.fr       */
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

template <typename T>
T next(T it, int steps) {
	//void std::advance(InputIterator& it, Distance n);
	std::advance(it, steps);
	return it;
}

template <typename T>
bool compare(T lv, T rv) { return *lv < *rv; }

long jacobsthal_numbers(long n);

template <typename T>
void PmergeMe::swap_pair(T it, int order) {
	T start = next(it, -order + 1);
	T end = next(start, order);
	while (start != end) {
		std::iter_swap(start, next(start, order));
		//std::iter_swap(ForwardIterator1 a, ForwardIterator2 b);
		start++;
	}
}

template <typename T>
void PmergeMe::insert_with_jacobsthal(std::vector<typename T::iterator>& main, std::vector<typename T::iterator>& pend) {
	typedef typename T::iterator it;
	int prev_jacobsthal = jacobsthal_numbers(1);
	int inserted_numbers = 0;
	for (int k = 2;; k++) {
		int curr_jacobsthal = jacobsthal_numbers(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break;
		typename std::vector<it>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
		typename std::vector<it>::iterator bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers);
		int size_to_pick = jacobsthal_diff, offset = 0;
		while (size_to_pick) {
			typename std::vector<it>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, compare<it>);
			typename std::vector<it>::iterator inserted = main.insert(idx, *pend_it);
			size_to_pick--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			int index = inserted - main.begin();
			int sum = curr_jacobsthal + inserted_numbers;
			offset += (index == sum) ? 1 : 0;
			bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}
}

template <typename T>
void PmergeMe::swap_adjacent_pairs(T& container, int order, typename T::iterator end) {
	typedef typename T::iterator it;
	int jump = 2 * order;
	for (it it1 = container.begin(); it1 != end; std::advance(it1, jump)) {
		it current_pair = next(it1, order - 1);
		it next_pair = next(it1, order * 2 - 1);
		if (*current_pair > *next_pair)
			swap_pair(current_pair, order);
	}
}

template <typename T>
void PmergeMe::merge_insertion_sort(T& container, int order) {
	typedef typename T::iterator it;
	int pair_size = container.size() / order;
	if (pair_size < 2)
		return;
	bool is_odd = pair_size % 2 == 1;
	it last = next(container.begin(), order * pair_size);
	it end = next(last, -(is_odd * order));
	swap_adjacent_pairs(container, order, end);
	merge_insertion_sort(container, order * 2);
	std::vector<it> main;
	std::vector<it> pend;
	main.insert(main.end(), next(container.begin(), order - 1));
	main.insert(main.end(), next(container.begin(), order * 2 - 1));
	for (int i = 4; i <= pair_size; i += 2) {
		pend.insert(pend.end(), next(container.begin(), order * (i - 1) - 1));
		main.insert(main.end(), next(container.begin(), order * i - 1));
	}
	insert_with_jacobsthal<T>(main, pend);
	for (size_t i = 0; i < pend.size(); i++) {
		typename std::vector<it>::iterator curr_pend = next(pend.begin(), i);
		typename std::vector<it>::iterator curr_bound = next(main.begin(), main.size() - pend.size() + i);
		typename std::vector<it>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, compare<it>);
		main.insert(idx, *curr_pend);
	}
	if (is_odd) {
		typename T::iterator odd_pair = next(end, order - 1);
		typename std::vector<it>::iterator idx = std::upper_bound(main.begin(), main.end(), odd_pair, compare<it>);
		main.insert(idx, odd_pair);
	}
	std::vector<int> temp;
	temp.reserve(container.size());
	for (typename std::vector<it>::iterator iter = main.begin(); iter!= main.end(); iter++) {
		for (int i = 0; i < order; i++) {
			it order_start = *iter;
			std::advance(order_start, -order + i + 1);
			temp.insert(temp.end(), *order_start);
		}
	}
	it container_it = container.begin();
	std::vector<int>::iterator itr = temp.begin();
	while (itr != temp.end()) {
		*container_it = *itr;
		container_it++;
		itr++;
	}
}

#endif