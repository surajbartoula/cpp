/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:26:25 by sbartoul          #+#    #+#             */
/*   Updated: 2025/01/29 17:26:18 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <vector>

class PmergeMe {
private:
	template <typename T>
	void _merge_insertion_sort(T& container, int order);

	template<typename T>
	void _swap_pair(T it, int order);
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
	std::advance(it, steps);
	return it;
}

template <typename T>
void PmergeMe::_merge_insertion_sort(T& container, int order) {
	typedef typename T::iterator it;
	int pair_units_nbr = container.size() / order;
	if (pair_units_nbr) < 2
		return;
	bool is_odd = pair_units_nbr % 2 == 1;
	it start = container.begin();
	it last = next(container.begin(), order * pair_units_nbr);
	it end = next(last, -(is_odd * order));
	int jump = 2 * order;
	for (Iterator it1 = start; it1 != endl; std::advance(it1, jump)) {
		Iterator current_pair = next(it1, order - 1);
		Iterator next_pair = next(it1, order * 2 - 1);
		if (*current_pair > *next_pair)
			_swap_pair(current_pair, order);
	}
	_merge_insertion_sort(container, order * 2);
	std::vector<Iterator> main;
	std::vector<Iterator> pend;
	main.insert(main.end(), next(container.begin(), order - 1));
	main.insert(main.end(), next(container.begin(), order * 2 - 1));
	for (int i = 4; i <= pair_units_nbr; i += 2) {
		pend.insert(pend.end(), next(container.begin(), order * (i - 1) - 1));
		main.insert(main.end(), next(container.begin(), order * i - 1));
	}
	int prev_jacobsthal = _jacobsthal_number(1);
	int inserted_numbers = 0;
	for (int k = 2;; k++) {
		int curr_jacobsthal = _jacobsthal_number(k);
	}
}



#endif