/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:21:25 by sbartoul          #+#    #+#             */
/*   Updated: 2025/02/02 23:00:54 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Iterator>
bool issorted(Iterator begin, Iterator end) {
	if (begin == end) return true;
	Iterator prev = begin;
	for (++begin; begin != end; ++begin) {
		if (*begin < *prev)
			return false;
		prev = begin;
	}
	return true;
}

static std::vector<int> argv_to_vector(int argc, char **argv) {
	std::vector<int> vec(argc - 1);
	for (int i = 1; i < argc; i++) {
		long nbr = strtol(argv[i], NULL, 10);
		vec[i - 1] = static_cast<int>(nbr);
	}
	return vec;
}

static std::list<int> argv_to_lst(int argc, char **argv) {
	std::list<int> lst;
	for (int i = 1; i < argc; i++) {
		long nbr = strtol(argv[i], NULL, 10);
		lst.push_back(static_cast<int>(nbr));
	}
	return lst;
}

static void print_argv(int argc, char **argv, const std::vector<int>& vec) {
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::vector<int>::size_type i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe + numbers to sort" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		char *end;
		long nbr = strtol(argv[i], &end, 10);
		if (nbr > INT_MAX || nbr < 0 || errno == ERANGE || *end != '\0' || end == argv[i])
		{
			std::cout << "Error: Please provide positive integer sequence as argument." << std::endl;
			return 1;
		}
	}
	PmergeMe pm;
	std::clock_t start1 = std::clock();
	std::vector<int> vec = argv_to_vector(argc, argv);
	pm.sort_vec(vec);
	std::clock_t end1 = std::clock();
	double elapsed_vec = (double(end1 - start1) / CLOCKS_PER_SEC);

	std::clock_t start2 = std::clock();
	std::list<int> lst = argv_to_lst(argc, argv);
	pm.sort_list(lst);
	std::clock_t end2 = std::clock();
	double elapsed_lst = (double(end2 - start2) / CLOCKS_PER_SEC);
	if (!issorted(lst.begin(), lst.end()))
		std::cout << "The list is not sorted." << std::endl;
	print_argv(argc, argv, vec);
	std::cout << "Time to process a range of " << vec.size()
			<< " elements with std::vector: " << std::fixed
			<< elapsed_vec << " us\n";
	std::cout << "Time to process a range of " << vec.size()
			<< " elements with std::list: " << std::fixed
			<< elapsed_lst << " us\n";
	return 0;
}
